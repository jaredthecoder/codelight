#!/usr/bin/env python

import os
import binascii
from flask import Flask, render_template, redirect
from flask.ext.uploads import UploadSet, TEXT, configure_uploads, patch_request_class
from flask.ext.wtf import Form
from flask.ext.wtf.file import FileField, FileAllowed, FileRequired
from wtforms import StringField
from wtforms.validators import DataRequired
from werkzeug import secure_filename

app = Flask(__name__)
app.secret_key = os.urandom(32)

destination = 'solutions'
solutions = UploadSet('solutions', TEXT, lambda app: destination)
configure_uploads(app, (solutions))
patch_request_class(app, 16 * 1024)


class SolutionForm(Form):
    first_name = StringField('First Name', validators=[DataRequired()])
    middle_initial = StringField('Middle Initial', validators=[DataRequired()])
    last_name = StringField('Last Name', validators=[DataRequired()])
    solution = FileField('solution', validators=[
        FileRequired(),
        FileAllowed(solutions, 'Solution source code only!')
    ])

    def validate_on_submit(self):
        rv = Form.validate(self)
        if not rv:
            return False
	return True


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/problem/1', methods=('GET', 'POST'))
def problem_1():
    filename = None
    form = SolutionForm()
    if form.is_submitted():
        if form.validate_on_submit():
	    filename = secure_filename(form.solution.data.filename)
	    tag = binascii.hexlify(os.urandom(6))
	    name = '-'.join([form.first_name.data, form.middle_initial.data, form.last_name.data])
	    print(name)
	    form.solution.data.save('problem1/' + name + '-problem-1-' + tag + '.cpp')
	    return redirect('/success')
	else:
	    return redirect('/failure')
    return render_template('problem.html', problem_number=1, form=form, filename=filename)


@app.route('/problem/2', methods=('GET', 'POST'))
def problem_2():
    filename = None
    form = SolutionForm()
    if form.is_submitted():
        if form.validate_on_submit():
	    filename = secure_filename(form.solution.data.filename)
	    tag = binascii.hexlify(os.urandom(6))
	    name = '-'.join([form.first_name.data, form.middle_initial.data, form.last_name.data])
	    print(name)
	    form.solution.data.save('problem2/' + name + '-problem-2-' + tag + '.cpp')
	    return redirect('/success')
	else:
	    return redirect('/failure')
    return render_template('problem.html', problem_number=2, form=form, filename=filename)


@app.route('/success', methods=('GET', 'POST'))
def success():
    return render_template('success.html')


@app.route('/failure', methods=('GET', 'POST'))
def failure():
    return render_template('failure.html')


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=8001)
