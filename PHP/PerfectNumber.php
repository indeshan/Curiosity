<?php
/*
	Perfect Number:
		Check if a number is Perfect number?
		A perfect number is a number if it is equal to the sum of its factors,that is original number is equal to sum of all its factors excluding the number itself.
*/

	function isPerfectNumber($N) {
		$sum = 0;

		for ($i = 1; $i < $N; $i++) {
			if ($N % $i == 0) {
				$sum = $sum + $i;
			}
		}
		return $sum == $N;
	}

	$N = 24;

	if (isPerfectNumber($N))
		echo "Perfect Number";
	else
		echo "Not Perfect Number"; 
?> 
