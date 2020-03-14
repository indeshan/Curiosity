<?php
	function factorial($num) {
		$factorial = 1;
		for ($x=$num; $x>=1; $x--) {
			$factorial = $factorial * $x;
		}
		return $factorial;
	}

	$num = 6;
	$factorial = factorial($num);
	
	echo "Factorial of ".$num ." is ".$factorial;
	?>  