<?php
   function solution($str) {
     return strlen($str) %2==0? str_split($str,2):str_split($str.'_',2);
   }

 $pairs = solution('cdabefg1');
 print_r($pairs);
