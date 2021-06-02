#!/bin/python3

from app import models
from config import *
from flask import flash, redirect, url_for, session, render_template

def register_user(form):
    ret = models.create_user(form['username'], form['password'])
    resp = {}
    if ret < 0:
        resp['error'] = 'internal error'
    elif ret == 0:
        resp['error'] = 'account already exists'
    else:
        resp['result'] = 'account created'
    flash(resp)
    return (redirect(url_for('root')))

def signin(form):
    user = models.get_user(form['username'])
    resp = {}
    if user is None or user.passwd != form['password']:
        resp['error'] = 'login or password does not match'
    elif session.get('user'): # already logged in
        resp['error'] = 'internal error'
    else:
        resp['result'] = 'signin successful'
        session['user'] = user.name
        session['id'] = user.id
    flash(resp)
    return (redirect(url_for('root')))

def signout():
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
    else:
        resp['result'] = 'signout successful'
        session['user'] = None
        session['id'] = None
    flash(resp)
    return (redirect(url_for('root')))

def user():
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    else:
        user = models.get_user(session['user'])
        return (render_template("user.html", user=user))

def view_all_tasks():
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    else:
        tasks = models.get_all_task(session['user'])
        if len(tasks) < 0:
            resp['error'] = 'internal error'
            flash(resp)
            return (redirect(url_for('root')))
        return (render_template("task.html", tasks=tasks))

def view_task(id):
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    task = models.get_task(session['user'], id)
    if not task:
        resp['error'] = 'task id does not exist'
        flash(resp)
        return (redirect(url_for('root')))
    return (render_template("update.html", task=task))

def create_task(form):
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    ret = models.create_task(session['user'], form['title'], form['begin'], form['end'], form['status'])
    if ret < 0:
        resp['error'] = 'internal error'
    else:
        resp['result'] = 'new task added'
    flash(resp)
    return (redirect(url_for('task_read')))

def delete_task(id):
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    ret = models.delete_task(id)
    if ret < 0:
        resp['error'] = 'internal error'
    else:
        resp['result'] = 'task deleted'
    flash(resp)
    return (redirect(url_for('root')))

def update_task(id, form):
    resp = {}
    if not session.get('user'):
        resp['error'] = 'you must be logged in'
        flash(resp)
        return (redirect(url_for('root')))
    task = models.get_task(session['user'], id)
    if not task:
        resp['error'] = 'task id does not exist'
        flash(resp)
        return (redirect(url_for('root')))
    ret = models.update_task(id, form['title'], form['begin'], form['end'], form['status'])
    if ret < 0:
        resp['error'] = 'internal error'
    else:
        resp['result'] = 'update done'
    flash(resp)
    return (redirect(url_for('root')))
