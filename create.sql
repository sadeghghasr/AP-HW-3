CREATE TABLE Users(
id SERIAL,
‫‪telegram_id VARCHAR(255) NOT NULL,
‫‪phone VARCHAR(255) NOT NULL,
‫‪email VARCHAR(255) NOT NULL,
‫‪password VARCHAR(255) NOT NULL,‫‪
first_name VARCHAR(255) NOT NULL,
last_name VARCHAR(255) NOT NULL,‫‪
‫‪verification_code VARCHAR(255) NOT NULL,
‫‪profil_picture_url‬‬ VARCHAR(255) NOT NULL,
‫‪created_at TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL

);

create table BlockUser( 
blocker_user_id varchar(255) NOT NULL,
‬‬‫‪blocked_user_id varchar(255) NOT NULL,
‬‬created_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(blocker_user_id,blocked_user_id),
FOREIGN KEY(blocker_user_id,blocked_user_id) REFERENCES User(telegram_id)
)‪;

create table Message(
id serial,
‫‪sender_id‬‬ varchar(255) NOT NULL,
‫‪receiver_id‬‬ varchar(255) NOT NULL,
‫‪message_type‬‬  varchar(255) NOT NULL,
‫‪message_text‬‬ varchar(255) NOT NULL,
created_at‬‬ TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(id,sender_id‬‬,receiver_id‬‬),
FOREIGN KEY(blocker_user_id,blocked_user_id) REFERENCES User(telegram_id)
);
create table Channel(
id serial,
‫‪telegram_id‬‬ varchar(255) NOT NULL,
‫‪title‬‬ varchar(255) NOT NULL,
‫‪info‬‬ varchar(255) NOT NULL,
c‫‪reator_id‬ varchar(255) NOT NULL,‬
created_at‬‬ TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(telegram_id‬‬),
FOREIGN KEY(c‫‪reator_id‬) REFERENCES User(telegram_id)
);
create table Group(
id serial,
c‫‪reator_id‬ varchar(255) NOT NULL,‬
title‬‬ varchar(255) NOT NULL,
‫‪join_url‬‬ varchar(255) NOT NULL,
created_at‬‬ TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(join_url‬‬),
FOREIGN KEY(c‫‪reator_id‬) REFERENCES User(telegram_id)
);
create table GroupMessage(
id serial,
‫‪group_id‬‬ varchar(255) NOT NULL,
‫‪sender_id‬‬ varchar(255) NOT NULL,
‫‪message_type‬‬ varchar(255) NOT NULL,
‫‪message_text‬‬ varchar(255) NOT NULL,
created_at‬‬ TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(group_id,sender_id‬‬,created_at‬‬),
FOREIGN KEY(sender_id‬‬) REFERENCES User(telegram_id),
FOREIGN KEY(group_id‬‬) REFERENCES Group(join_url‬‬),
FOREIGN KEY(message_type‬‬) REFERENCES Message(message_type‬‬),
FOREIGN KEY(message_text‬‬) REFERENCES Message(message_text‬‬)
);
create table ChannelMessage(
id serial,
‫‪channel_id‬‬ varchar(255) NOT NULL,
‫‪message_type‬‬ varchar(255) NOT NULL,
‫‪message_text‬‬ varchar(255) NOT NULL,
created_at‬‬ TIMESTAMP NOT NULL,
‫‪updated_at‬‬ TIMESTAMP NOT NULL,
PRIMARY KEY(channel_id‬‬,created_at‬‬),
FOREIGN KEY(channel_id‬‬) REFERENCES Channel(telegram_id‬‬)
);

create table MessageAttachment(
‫‪message_id‬‬ varchar(255) NOT NULL,
‫‪attachment_url‬‬ varchar(255) NOT NULL,
‫‪attachment_thumb_url‬‬ varchar(255) NOT NULL
);