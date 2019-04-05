#!/usr/bin/perl

# find the smallest in array and swap it with first element, do the same with 2nd, 3rd...upto n-1.

@array=(6,2,7,3,5,9,1);
$length=@array;

print "Before Selection Sort: @array\n";

for($i=0;$i<($length-1);$i++)
{
  $min=$i;
  for($j=$i+1;$j<$length;$j++)
  {
    if ( $array[$j] < $array[$min] ) 
    {
      $min=$j;
    }
    print "i=$i; j=$j; During Selection Sort: @array\n";
  }
  
  $temp=$array[$i];
  $array[$i]=$array[$min];
  $array[$min]=$temp;
}

print "After Selection Sort: @array\n";
