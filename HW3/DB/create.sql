CREATE TABLE Users(
	id SERIAL NOT NULL,
	telegram_id VARCHAR(255) unique,
	phone VARCHAR (13) NOT NULL unique,
	email VARCHAR (255) NOT NULL,
	first_name VARCHAR(255) NOT NULL,
	last_name VARCHAR(255) NOT NULL,
	verification_code VARCHAR(255) NOT NULL,
	profile_picture_url VARCHAR(255) NOT NULL,
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY(id)

);

CREATE TABLE BlockUser(
	blocker_user_id VARCHAR(255),
	blocked_user_id VARCHAR(255),
	ecrated_at TIMESTAMP NOT NULL,
	PRIMARY KEY(blocker_user_id,blocked_user_id),
	FOREIGN KEY (blocker_user_id) REFERENCES Users(telegram_id),
	FOREIGN KEY (blocked_user_id) REFERENCES Users(telegram_id)
);

CREATE TABLE Message(
	id SERIAL NOT NULL unique,
	sender_id VARCHAR(255) NOT NULL,
	reciever_id VARCHAR(255) NOT NULL,
	message_type VARCHAR(255) NOT NULL,
	message_text VARCHAR(255),
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY (id,sender_id,reciever_id),
	FOREIGN KEY (sender_id) REFERENCES Users(telegram_id),
	FOREIGN KEY (reciever_id) REFERENCES Users(telegram_id)

);

CREATE TABLE Channel(
	id SERIAL NOT NULL unique,
	telegram_id VARCHAR(255) unique,
	title VARCHAR(255) NOT NULL,
	info VARCHAR(255) NOT NULL,
	creator_id VARCHAR(255) NOT NULL,
	created_at TIMESTAMP NOT NULL,	
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (creator_id) REFERENCES Users(telegram_id)
);

CREATE TABLE Groups( 
	id SERIAL NOT NULL unique,
	creator_id VARCHAR(255) NOT NULL,
	title VARCHAR(255) NOT NULL,
	join_url VARCHAR(255) NOT NULL unique,
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY(id),
	FOREIGN KEY (creator_id) REFERENCES Users(telegram_id)
);

CREATE TABLE GroupMessage(
	id SERIAL NOT NULL unique,
	group_id VARCHAR(255) NOT NULL,
	sender_id VARCHAR(255) NOT NULL,
	message_type VARCHAR(255) NOT NULL,
	message_text VARCHAR(255),
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY(id,group_id),
	FOREIGN KEY (group_id) REFERENCES Groups(join_url),
	FOREIGN KEY (sender_id) REFERENCES Users(telegram_id)
);

CREATE TABLE ChannelMessage(
	id SERIAL NOT NULL unique,
	channel_id SERIAL NOT NULL,
	message_type VARCHAR(255) NOT NULL,
	message_text VARCHAR(255),
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,
	PRIMARY KEY(id,channel_id),
	FOREIGN KEY (channel_id) REFERENCES Channel(id)
);

CREATE TABLE MessageAttachment(
	message_id SERIAL,
	‫attachment_url‬ VARCHAR(255) NOT NULL,
	‬‫‪attachment_thumb_url‬‬ VARCHAR(255) NOT NULL,
	PRIMARY KEY(message_id),
	FOREIGN KEY(message_id) REFERENCES Message(id)
);

CREATE TABLE GroupMessageAttachment(
	message_id SERIAL,
	attachment_url‬ VARCHAR(255) NOT NULL,
	attachment_thumb_url‬‬ VARCHAR(255) NOT NULL,
	PRIMARY KEY(message_id),
	FOREIGN KEY(message_id) REFERENCES GroupMessage(id)
);

CREATE TABLE ChannelMessageAttachment(
	message_id SERIAL,
	attachment_url‬ VARCHAR(255) NOT NULL,
	attachment_thumb_url‬‬ VARCHAR(255) NOT NULL,
	PRIMARY KEY(message_id),
	FOREIGN KEY(message_id) REFERENCES ChannelMessage(id)	
);

CREATE TABLE ChannelMembership(
	user_id SERIAL,
	channel_id VARCHAR(255),
	created_at TIMESTAMP NOT NULL,
	PRIMARY KEY(user_id,channel_id),
	FOREIGN KEY(user_id) REFERENCES Users(id),
	FOREIGN KEY(channel_id) REFERENCES Channel(telegram_id)

);

CREATE TABLE GroupMembership(
	user_id SERIAL NOT NULL,
	group_id SERIAL NOT NULL,
	created_at TIMESTAMP NOT NULL,
	PRIMARY KEY(user_id,group_id),
	FOREIGN KEY(user_id) REFERENCES Users(id),
	FOREIGN KEY(group_id) REFERENCES Groups(id)
);

