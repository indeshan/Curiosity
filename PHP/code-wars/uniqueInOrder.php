<?php
/*
 Implement the function unique_in_order which takes as argument a sequence and returns a list of items without any elements with the same value next to each other and preserving the original order of elements.

For example:

uniqueInOrder("AAAABBBCCDAABBB") == {'A', 'B', 'C', 'D', 'A', 'B'}
uniqueInOrder("ABBCcAD")         == {'A', 'B', 'C', 'c', 'A', 'D'}
uniqueInOrder([1,2,2,3,3])       == {1,2,3}
*/

function uniqueInOrder($iterable){
if(is_array($iterable))
  $len = count($iterable);
else
  $len = strlen($iterable);
$pre = null;
$cur = null;
$ret = [];
for($i=0; $i<$len; $i++) {
	$cur = $iterable[$i];
	if($cur != $pre)
		array_push($ret, $iterable[$i]);
	$pre = $cur;
}
  return $ret;
}

print_r(uniqueInOrder('AAAABBBCCDAABBB'));

?>
