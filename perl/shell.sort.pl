#!/usr/bin/perl

# Same as Insersion sort, except, we swap the elements that are wide (as wide as the $increment variable) apart.

#@array = (1,2,3,4,5,6,8);
@array=(8,6,4,3,3,2,1);
$arraysize = @array;
$increment=int($arraysize/2);
print "increment=$increment;Before Shell Sort: @array\n";

while ($increment gt 0)
{
  for ($i=$increment; $i<$arraysize; $i++)
  {
    $temp=$array[$i];
    $j=$i;
    while ($j ge $increment and $array[$j] lt $array[$j-$increment])
    {
      $array[$j]=$array[$j-$increment];
      $j = $j - $increment;
      $array[$j]=$temp;
      print "increment=$increment; i=$i; j=$j; During Shell Sort: @array\n";
    }
  }
    $increment=int($increment/2);
}

print "increment=$increment;After Shell Sort: @array\n";
exit 0
