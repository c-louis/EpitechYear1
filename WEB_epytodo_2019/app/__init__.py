#!/bin/python3

from flask import Flask
import pymysql as sql

srv = Flask(__name__)
srv.config.from_object('config')
srv.secret_key = b'_5#y2L"F4Q8z\n\xec]/'

try:
    db = sql.connect(host=srv.config['DATABASE_HOST'],
                     unix_socket=srv.config['DATABASE_SOCK'],
                     user=srv.config['DATABASE_USER'],
                     passwd=srv.config['DATABASE_PASS'],
                     db=srv.config['DATABASE_NAME'])
except Exception as error:
    print("Could not connect to database :", error)
    exit(84)

from app.controller import *
from app.models import *

from flask.json import JSONEncoder
class serializer(JSONEncoder):
    def default(self, obj):
        if type(obj) is User:
            return {
                'username': obj.name,
                'password': obj.passwd,
                'id': obj.id,
            }
        return super(serializer, self).default(obj)
srv.json_encoder = serializer

from app import views
