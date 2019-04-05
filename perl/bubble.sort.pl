#!/usr/bin/perl

# Compare adjecent elements and swap them if needed(if the one on right is smaller than the left). 
# Do the same from start to end, n times, dumping the smallest element in left everytime.

@array = (8,3,5,1,2,7,4);
$length = @array;

print "Before Bubble Sort: @array\n";
for ($i=1;$i<$length;$i++)
{
  for ($j=$i;$j>0;$j--)
  {
    if ($array[$j]<$array[$j-1])
	{
	  $temp=$array[$j-1];
	  $array[$j-1]=$array[$j];
	  $array[$j]=$temp;
	}
    print "i=$i; j=$j; During Bubble Sort: @array\n";
  }
}
print "After Bubble Sort: @array\n";
