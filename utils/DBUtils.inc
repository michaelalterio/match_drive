<?php

include_once("./config/database.cfg");


//=============================================
// queryDataBase($string) - calls the performQuery in ../common/inc/dbutils with DB info from config file
//=============================================
function queryDataBase($string){

	include("./config/database.cfg");

	return (performQuery($cfg['DB_NAME'],$cfg['DB_USER'],$cfg['DB_PASSWORD'],$string));

} // end function



//=============================================
// getDBName() - returns name of Database
//=============================================
function getDBName(){

	include("./config/database.cfg");
	return $cfg['DB_NAME'];

} // end function



//=============================================
// getDatabase($dbname,$user) - connect to database  
//=============================================
function getDatabase($dbname,$user,$password) {


  	$db = mysql_connect("localhost", $user, $password);
  	
  	$status = mysql_select_db($dbname, $db);
	
  	if (!$status){

    		displayDBError($db,"Could not connect to the DB"); 
    		exit(1);

  	} // end if

  	return $db;

} // end function



//=============================================
// performQuery($dbname, $user, $string) - perform a query on the specified DB
//=============================================
 function performQuery($dbname, $user, $password, $string) {

	$db = getDatabase($dbname,$user,$password);

	$result = mysql_query($string, $db);

	if ($result <= 0) {
	
		displayDBError($db,$string); 
		mysql_close($db);
		exit(1);

	} // end if

	mysql_close($db);

	return $result;

} // end function



//=============================================
// displayDBError - for DB query errors
//=============================================
function displayDBError($db,$string) {


  	echo	"<table id='database-error'>
			<tr>
				<td>MYSQL error is $db</td>
				<td class='right'>MySQL Error ".mysql_errno($db).": ".mysql_error($db)."</td>
			</tr>
			<tr>
				<td colspan='2'><hr></td>
			</tr>
			<tr>
				<td colspan='2' class='title'>The following statement could not be executed:</td>
			</tr>
			<tr>
				<td colspan='2' class='errorString'>$string</td>
			</tr>

		</table>";

} // end function

?>