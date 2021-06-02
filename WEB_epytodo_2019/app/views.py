#!/bin/python3

from app import srv, db, controller
from flask import render_template, jsonify, request

## Define default Route

@srv.route('/', methods=['GET'])
def root():
    return render_template("index.html")

## Define User Route

@srv.route('/register', methods=['POST'])
def register():
    return controller.register_user(request.form)
@srv.route('/signin', methods=['POST'])
def signin():
    return controller.signin(request.form)
@srv.route('/signout', methods=['POST'])
def signout():
    return controller.signout()
@srv.route('/user', methods=['GET'])
def user():
    return controller.user()

## Define task Route

@srv.route('/user/task', methods=['GET'])
def task_read():
    return controller.view_all_tasks()
@srv.route('/user/task/<id>', methods=['GET', 'POST'])
def task_update(id):
    if request.method == 'POST':
        return controller.update_task(id, request.form)
    return controller.view_task(id)
@srv.route('/user/task/add', methods=['POST'])
def task_create():
    return controller.create_task(request.form)
@srv.route('/user/task/del/<id>', methods=['POST'])
def task_delete(id):
    return controller.delete_task(id)
