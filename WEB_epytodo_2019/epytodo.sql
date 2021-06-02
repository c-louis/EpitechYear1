CREATE DATABASE IF NOT EXISTS epytodo;
USE epytodo;
CREATE TABLE IF NOT EXISTS user (
  id int NOT NULL auto_increment PRIMARY KEY,
  username varchar(255) NOT NULL,
  password varchar(255) NOT NULL
);
CREATE TABLE IF NOT EXISTS task (
  id int NOT NULL auto_increment PRIMARY KEY,
  title TEXT NOT NULL,
  begin DATETIME DEFAULT CURRENT_TIMESTAMP,
  end DATETIME DEFAULT NULL,
  status ENUM ('not_started', 'in_progress', 'done')
);
CREATE TABLE IF NOT EXISTS user_has_task (
  fk_user_id int,
  fk_task_id int,
  FOREIGN KEY (fk_user_id) REFERENCES user(id) ON DELETE CASCADE,
  FOREIGN KEY (fk_task_id) REFERENCES task(id) ON DELETE CASCADE
);