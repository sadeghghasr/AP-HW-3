--question 1--
SELECT* FROM Users WHERE phone='09120000001';
--question 2--
UPDATE Users SET email = 'apstudent2019@gmail.com' WHERE phone='09120000001';
--question 3--
SELECT channel_id from channelmembership where user_id=(SELECT id FROM Users WHERE phone = '09120000001');
--question 4--
SELECT COUNT(*) FROM channelmembership WHERE channel_id = '@aut_ap_2019'; 
-- question 5--
SELECT email FROM Users WHERE phone LIKE '0935_%_%';

SELECT blocked_user_id FROM BlockUser WHERE blocker_user_id = (SELECT telegram_id FROM users WHERE phone ='09120000001'); 
--question 6--
SELECT phone FROM Users WHERE telegram_id in(SELECT blocked_user_id FROM BlockUser WHERE blocker_user_id = (SELECT telegram_id FROM users WHERE phone ='09120000001') AND (ecrated_at BETWEEN now() - INTERVAL '1' month AND now()));

--question 7--
SELECT email FROM users WHERE telegram_id in(SELECT creator_id FROM Channel WHERE telegram_id in(SELECT channel_id FROM channelmembership WHERE user_id in(SELECT id FROM users WHERE email = 'apstudent2019@gmail.com') and 
	channel_id in (SELECT channel_id FROM channelmembership GROUP BY channel_id HAVING COUNT(*) > 3 )));

--question 8--
SELECT message_text FROM message WHERE (sender_id = '@amir.jahanshahi' AND reciever_id = '@sHDiV4RHs') OR (reciever_id = '@amir.jahanshahi' AND sender_id = '@sHDiV4RHs') ORDER BY id DESC LIMIT 10;
delete FROM message WHERE (sender_id = '@amir.jahanshahi' AND reciever_id = '@sHDiV4RHs') OR (reciever_id = '@amir.jahanshahi' AND sender_id = '@sHDiV4RHs');

--question 9--

SELECT phone FROM Users WHERE telegram_id in (SELECT creator_id FROM channel WHERE updated_at NOT BETWEEN now() - INTERVAL '1' month AND now() );

UPDATE channel 
SET updated_at  = '2018-02-11 00:48:18.641029' where creator_id = '@sadegh';