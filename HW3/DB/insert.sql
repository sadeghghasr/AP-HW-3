INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@sadegh','09120000001','abcd@gmail.com',MD5('sad_password'),'sadegh','ghasrizadeh',now(),'fisrt',
		'desktop',now());

INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@Javad','09350000002','apstudent2019@gmail.com',MD5('Jav_password'),'Javad','ghasrizadeh',now(),'seventh',
		'desktop',now());


INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@hassan','09351234567','hassan@gmail.com',MD5('hassan_password'),'hassan','ghasrizadeh',now(),'third',
		'desktop',now());

INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@amir.jahanshahi','09351101101','amir@gmail.com',MD5('amir_password'),'amir','Jahanshahi',now(),'fifth',
		'desktop',now());

INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@sHDiV4RHs','09351111111','sHD@gmail.com',MD5('sHD_password'),'sHD','iV4RHs',now(),'sixth',
		'desktop',now());

INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@taghi','09357654321','taghi@gmail.com',MD5('taghi_password'),'taghi','ghasrizadeh',now(),'fourth',
		'desktop',now());


INSERT INTO Channel(telegram_id,title,info,creator_id,created_at,updated_at)
	VALUES('@gizmiz','GIZ_MIZ','gizmiz',(select telegram_id from users where first_name='sadegh')
		,now(),now());

INSERT INTO Users (telegram_id,phone,email,password,first_name,last_name,created_at,verification_code,
profile_picture_url,updated_at)
	VALUES('@ali','09120000854','ali@gmail.com',MD5('ali_password'),'ali','ghasrizadeh',now(),'second',
		'desktop',now());

INSERT INTO Channel(telegram_id,title,info,creator_id,created_at,updated_at)
	VALUES('@aut_ap_2019','AP_2019','Dr.Jahanshahi',(select telegram_id from users where first_name='ali')
		,now(),now());

INSERT INTO Channel(telegram_id,title,info,creator_id,created_at,updated_at)
	VALUES('@communication_AUT','COMMUNICATION_2019','Dr.Emadi',(select telegram_id from users where first_name='ali')
		,now(),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09120000001'),(select telegram_id from Channel where telegram_id = '@aut_ap_2019'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09120000001'),(select telegram_id from Channel where telegram_id='@gizmiz'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09120000854'),(select telegram_id from Channel where telegram_id='@gizmiz'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09120000854'),(select telegram_id from Channel where telegram_id='@aut_ap_2019'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09351234567'),(select telegram_id from Channel where telegram_id='@aut_ap_2019'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09357654321'),(select telegram_id from Channel where telegram_id='@aut_ap_2019'),now());

INSERT INTO ChannelMembership(user_id,channel_id,created_at)
	VALUES((select id from users where phone='09350000002'),(select telegram_id from Channel where telegram_id='@aut_ap_2019'),now());


INSERT INTO BlockUser(blocker_user_id,blocked_user_id,ecrated_at)
	VALUES((select telegram_id from users where phone='09120000001'),(select telegram_id from users where telegram_id='@ali'),now());

INSERT INTO BlockUser(blocker_user_id,blocked_user_id,ecrated_at)
	VALUES((select telegram_id from users where phone='09120000001'),(select telegram_id from users where telegram_id='@taghi'),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@amir.jahanshahi','@sHDiV4RHs','text','HI', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@amir.jahanshahi','@sHDiV4RHs','text','HOY', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@amir.jahanshahi','@sHDiV4RHs','text','HEY', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@amir.jahanshahi','@sHDiV4RHs','text','BYE', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@amir.jahanshahi','@sHDiV4RHs','text',':)', now(),now());


INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','I Have DB Exercise... I will answer you tomorrow!!! GoodBy :) ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now1', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now2', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now3 ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now 4 ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now 5 ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now 6 ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','now7 ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sHDiV4RHs','@amir.jahanshahi','text','I Have DB Exercise... I will answer you tomorrow!!! GoodBy :) ', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@ali','@sadegh','text','Hello How are you?', now(),now());

INSERT INTO Message(sender_id,reciever_id,message_type,message_text,created_at,updated_at)
	VALUES('@sadegh','@ali','text','Hello How are you?', now(),now());
