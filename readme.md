To configure database settings go to config/database.cfg. There you can update database name, username, and password for localhost. The database name I created is ajax_db.

Within database ajax_db there is one table named ajax_data. The query to create this table can be found in the file ajax_data.sql or by copying and pasting the following in the sql query window:

CREATE TABLE IF NOT EXISTS `ajax_data` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(200) NOT NULL,
  `email` varchar(200) NOT NULL,
  `dob` varchar(200) NOT NULL,
  `when` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;



Once these database changes are complete, you should be able to test the site!



Link to live site:
http://michaelalterio.co/match_drive/index.php


Testing was done mainly on Chrome & Safari. Also tested on Firefox (was a bit slow with updating list), iPhone, and IE11. I don't have access to IE8 or IE9 - but it should work on those browsers.
