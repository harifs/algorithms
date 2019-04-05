#!/usr/bin/perl

## starting from 2nd element as index($temp) to last element in outer loop,
## sort everything from 1st element to index in inner loop, 
## Going from index to first element, swapping one at a time, till the number is less than index.

## Instead of (j-1) when we do a (j-increment), it becomes a shell sort, with an improved performance.

@array=(4,3,2,1,6,9,5);
#@array=(8,6,4,3,3,2,1);
#@array = (1,2,3,4,5,6,8);
$length = @array;

print "Before Insersion Sort: @array\n";

for ($i=1;$i<$length;$i++)
{
  $temp = $array[$i];
  $j = $i;
  while ($j>0 and $array[$j-1]>$temp)
  { 
    $array[$j]=$array[$j-1];
    $j-=1;
    print "i=$i; j=$j; During Insersion Sort: @array\n";
  }
  $array[$j]=$temp;
}

print "After Insersion Sort: @array\n";
