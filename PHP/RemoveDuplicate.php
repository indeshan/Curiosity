<?php

	function removeDuplicate($arr){
		$arr = array_flip($arr);
		$arr = array_flip($arr);
		$arr = array_values($arr);
		return $arr;
	}

	$arr = array(1, 5, 2, 5, 1, 3, 2, 4, 5);

	echo "Array before removing duplicate element:",PHP_EOL;
	print_r($arr);

	$arr = removeDuplicate($arr);

	echo PHP_EOL,"Array after removing duplicate element:",PHP_EOL;
	print_r($arr);
?>