#!/bin/sh

gunicorn --bind 0.0.0.0:8001 --pid /home/codelight/gunicorn.pid -w 4 "app:app"
