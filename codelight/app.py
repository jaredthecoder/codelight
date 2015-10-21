from flask import Flask, render_template
from flask.ext.uploads import UploadSet
from flask.ext.wtf import Form
from flask.ext.wtf.file import FileField, FileAllowed, FileRequired
from werkzeug import secure_filename

app = Flask('codelite')

solutions = UploadSet('solutions', TEXT)

class SolutionForm(Form):
    solution = FileField('solution', validators=[
        FileRequired(),
        FileAllowed(solutions, 'Solution source code only!')
    ])

@app.route('/')
def index():
    return render_template('templates/index.html')


@app.route('/problem/1', methods=('GET', 'POST))
def problem_1():
    form = SolutionForm()
    if form.validate_on_submit():
        filename = secure_filename(form.solution.data.filename)
        form.solution.data.save('uploads/' + filename)
    return render_template('templates/problem.html', problem_number=1, form=form, filename=filename)


@app.route('/problem/2', methods=('GET', 'POST'))
def problem_2():
    form = SolutionForm()
    if form.validate_on_submit():
        filename = secure_filename(form.solution.data.filename)
        form.solution.data.save('uploads/' + filename)
    return render_template('templates/problem.html', problem_number=2, form=form, filename=filename)


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=8001)
