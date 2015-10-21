#!/bin/sh

gunicorn --bind 0.0.0.0:8000 --pid /home/codelight/gunicorn.pid -w 1 "codelight.app:app"
