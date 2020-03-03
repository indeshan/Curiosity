<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
$big_array = array();

for ($i = 0; $i < 100000; $i++) {
	$big_array[] = $i;
}

echo 'After building the array.',PHP_EOL;
print_mem();

unset($big_array);

echo 'After unsetting the array.',PHP_EOL;
print_mem();


function print_mem() {
	/* Currently used memory */
	$mem_usage = memory_get_usage();

	/* Peak memory usage */
	$mem_peak = memory_get_peak_usage();

	echo 'The script is now using: ' . round($mem_usage / 1024) . 'KB of memory.',PHP_EOL;
	echo 'Peak usage: ' . round($mem_peak / 1024) . 'KB of memory.',PHP_EOL;
}
