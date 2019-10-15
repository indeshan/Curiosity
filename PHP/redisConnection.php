<?php
	$redis = new Redis();
	$redis->connect('127.0.0.1',6379);
	echo "Connected to server sucessfully",PHP_EOL;

	//Connection check
	echo "Server is running: ".$redis->ping(),PHP_EOL;

	//set and get string in redis
	$redis->set('name','foo');
	echo "Name of user: ".$redis->get('name'),PHP_EOL;
	
	//set and get list in redis
	$redis->lpush("tech","SOLR");
	$redis->lpush("tech","Python");
	$redis->lpush("tech","kafka");
	$redis->lpush("tech","linux");
	print_r($redis->lrange("tech",0,10));

	//get all redis keys
	print_r($redis->keys("*"));
?>