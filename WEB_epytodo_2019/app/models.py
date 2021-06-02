#!/bin/python3

from flask import render_template, jsonify, request
from app import db
from datetime import *
from dateutil.parser import parse


class User():
    def __init__(self, id, name, passwd):
        self.id = id
        self.name = name
        self.passwd = passwd
        pass

## USER CRUD

def create_user(user, passwd):
    if type(user) is not type('') or type(passwd) is not type(''):
        return (-1)
    if get_user(user) is not None:
        return (0)
    try:
        with db.cursor() as cursor:
            request = "INSERT INTO `user` (`username`, `password`) VALUES (%s, %s)"
            cursor.execute(request, (user, passwd))
            db.commit()
    except:
        return (-1)
    return (1)

def get_all_users():
    try:
        with db.cursor() as cursor:
            request = "SELECT * FROM `user`"
            cursor.execute(request);
            result = cursor.fetchall()
            users = []
            for res_user in result:
                if not res_user or len(res_user) != 3:
                    continue
                users.append(User(res_user[0], res_user[1], res_user[2]))
            return (users)
    except:
        return (None)
    return (None)

def get_user(user):
    if type(user) is not type(''):
        return (None)
    try:
        with db.cursor() as cursor:
            request = "SELECT * FROM `user` WHERE (`username`) = %s"
            cursor.execute(request, (user));
            result = cursor.fetchone()
            if not result or len(result) != 3:
                return (None)
            return (User(result[0], result[1], result[2]))
    except:
        return (None)
    return (None)

def update_user(user, oldpasswd, newpasswd):
    if type(user) is not type('') or type(oldpasswd) is not type('') or type(newpasswd) is not type(''):
        return (1)
    try:
        user = get_user(user)
        if oldpasswd != user.password:
            return (0)
        with db.cursor() as cursor:
            request = "UPDATE `user` SET `password` = %s WHERE (`username`) = %s"
            cursor.execute(request, (password, user));
            db.commit()
    except:
        return (-1)
    return (1)

def delete_user(user):
    if type(user) is not type(''):
        return (-1)
    try:
        with db.cursor() as cursor:
            request = "DELETE FROM `user` WHERE `username` = %s"
            cursor.execute(request, (user));
            db.commit()
    except:
        return (-1)
    return (1)

## TASK CRUD

class Task():
    def __init__(self, id, title, begin, end, status):
        self.id = id
        self.title = title
        self.begin = begin
        self.end = end
        self.status = status
        pass

def create_task(username, title, begin, end, status):
    begin = parse(begin)
    end = parse(end)
    if type(title) is not type(''):
        return (-1)
    if type(begin) is not type(datetime.now()):
        return (-1)
    if type(end) is not type(datetime.now()):
        return (-1)
    if type(username) is not type(''):
        return (-1)
    if (status != 'not_started' and status != 'in_progress'  and status != 'done'):
        return (-1)
    try:
        with db.cursor() as cursor:
            request = "INSERT INTO `task` (`title`, `begin`, `end`, `status`) VALUES (%s, %s, %s, %s)"
            cursor.execute(request, (title, begin, end, status))
            db.commit()
            task_id = cursor.lastrowid
            user_id = (get_user(username).id) # Get the id of the user
            request = "INSERT INTO `user_has_task` (`fk_user_id`, `fk_task_id`) VALUES (%s, %s)"
            cursor.execute(request, (user_id, task_id))
            db.commit()
    except Exception as ex:
        print(ex)
        return (-1)
    return (1)

def get_task(username, task_id):
    task_id = int(task_id)
    tasks = get_all_task(username)
    if len(tasks) <= 0:
        return None
    wanted_task = None
    for task in tasks:
        if task.id == task_id:
            wanted_task = task
            break
    return (wanted_task)

def get_all_task(username):
    if type(username) is not type(''):
        return (-1)
    try:
        with db.cursor() as cursor:
            request = "SELECT task.* FROM `user_has_task` AS idt INNER JOIN `task` AS task ON (idt.fk_task_id=task.id) AND (idt.fk_user_id=%s)"
            cursor.execute(request, (get_user(username)).id)
            result = cursor.fetchall()
            tasks = []
            for res_task in result:
                if not res_task or len(res_task) != 5:
                    continue
                tasks.append(Task(res_task[0], res_task[1], res_task[2], res_task[3], res_task[4]))
            return tasks
    except Exception as ex:
        print(ex)
        return (0)
    return (-1)

def update_task(task_id, title, begin, end, status):
    begin = parse(begin)
    end = parse(end)
    if type(title) is not type(''):
        return (-1)
    if type(begin) is not type(datetime.now()):
        return (-1)
    if type(end) is not type(datetime.now()):
        return (-1)
    if (status != 'not_started' and status != 'in_progress'  and status != 'done'):
        return (-1)
    try:
        with db.cursor() as cursor:
            request = "UPDATE `task` SET `title`= %s, `end` = %s, `begin` = %s, `status` = %s WHERE `id` = %s"
            cursor.execute(request, (title, end, begin, status, task_id))
            db.commit()
    except Exception as ex:
        print(ex)
        return (-1)
    return (1)

def delete_task(task_id):
    if type(task_id) is not type(''):
        return (-1)
    try:
        with db.cursor() as cursor:
            request = "DELETE FROM `task` WHERE `id` = %s"
            cursor.execute(request, (task_id));
            db.commit()
    except Exception as ex:
        print(ex)
        return (-1)
    return (1)
