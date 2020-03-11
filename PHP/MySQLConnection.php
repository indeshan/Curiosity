<?php
	$dbhost = 'localhost:3036';
	$dbuser = 'root';
	$dbpass = 'root';
	$conn = mysql_connect($dbhost, $dbuser, $dbpass);
	if(! $conn ) {
		die('Could not connect: ' . mysql_error());
	}
	mysql_select_db( 'test_db' );
	$sql = "SELECT address_line1,address_line2,address_line3 FROM addresses";
	$retval = mysql_query( $sql, $conn);
	while($row = mysql_fetch_array($retval, MYSQL_ASSOC)) {
		echo $row['address_line1']." ".$row['address_line2']." ".$row['address_line3']."<br>";
	}
	mysql_close($conn);
?>