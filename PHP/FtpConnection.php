<?php
	$conId = ftp_connect('127.0.0.1');
	echo $conId;
	$loginResult = ftp_login($conId, 'USERNAME', 'PASSWORD');
	//var_dump($loginResult);

	if ((!$conId) || (!$loginResult)) {
		echo "Login unsuccessful.";
	}
	else {
		echo "Login successful.";
	}

	echo ftp_pwd($conId);

	//Close this connection
	ftp_close($conId);
?>