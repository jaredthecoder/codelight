from flask import Flask, render_template
from flask.ext.uploads import UploadSet
from flask.ext.wtf import Form
from flask.ext.wtf.file import FileField, FileAllowed, FileRequired
from werkzeug import secure_filename

app = Flask('codelite')

@app.route('/')
def index():
    return render_template('templates/index.html')

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=8001)
