<?php


function beginHTML($title) {
	
	echo "<!DOCTYPE HTML>
			<html>

			<head>
				<meta charset='UTF-8'>
					<title>$title</title>";
	
} // end function


function endHTML() {
	
        // end div wrapper

	echo "</div></div></div></body></html>";
	
} // end function


function displayPageContainer() {

	
	echo "</head><body>
	
		<div id='page-container'>

			<div id='object-container'>";


} // end function



function displayHeader() {

	
	echo "</head><body><div id='wrapper'>";
	

	echo "<div id='header'>

		<div id='header_container'>

  			<ul>
            			<li><a class='match_logo' href='http://www.matchmg.com' target='_blank'></a></li>
   			</ul>
        
		</div>
    
	</div>";

} // end function



function linkCSS($path) {

	echo "<link href='$path' rel='stylesheet' type='text/css'>";

} // end function


function linkScript($path) {

	echo "<script src='$path' type='text/javascript'></script>";

} // end function


?>