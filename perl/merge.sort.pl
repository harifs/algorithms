#!/usr/bin/perl

# Divide the array recursively, till last 2 or 1 element left and merge them
# Since merging is linear (order of N), the worst case time is N times (N is number of element)

@array = (1,6,4,2,7,4,8);
$arraysize=@array;

print "Before Mergesort: arraysize=$arraysize; @array\n";

## usage: merge (low,middle,high)
sub merge
{
  $variablesPassed = @_;
  if ( $variablesPassed < 3) { print "usage: merge(low,middle,high)\n"; exit 1 }

  local($low,$middle,$high,$i,$j,$k,@helper);

  $low=$_[0];
  $middle=$_[1];
  $high=$_[2];

  @helper = @array;
  $i=$low;
  $j=$middle+1;
  $k=$low;


  ## start filling the array with smallest element to the left and so no.
  while ( $i le $middle and $j le $high)
  {
    if ($helper[$i] le $helper[$j])
    {
      $array[$k]=$helper[$i];
      $i++;
    }
    else
    {
      $array[$k]=$helper[$j];
      $j++;
    }
    $k++;
  }
 
  while ($i le $middle)
  {
    $array[$k]=$helper[$i];
    $i++;
    $k++;
  }

  ### For an Explanatory OUTPUT ###
  print "After Merge: low=$low; middle=$middle; high=$high; array=(";
  for ($count3=$low;$count3<=$high;$count3++){print "$array[$count3],"} print ")\n";
}

## usage: mergesort (low,high)
sub mergesort
{
  $variablesPassed = @_;
  if ( $variablesPassed < 2) { print "usage: mergesort(low,high)\n"; exit 1 }

  local($low,$middle,$high);
  $low=$_[0];
  $high=$_[1];
  $middle=int(($low+$high)/2);

  ### For an Explanatory OUTPUT ###
  print "During Mergesort: low=$low; middle=$middle; high=$high; array=(";
  for ($count3=$low;$count3<=$high;$count3++){print "$array[$count3],"} print ")\n";

  if ($low lt $high)
  {
    &mergesort($low,$middle);
    &mergesort($middle+1,$high);
    &merge($low,$middle,$high);
  }
}

## Main Program
&mergesort(0,$arraysize-1);
print "After Mergesort: @array\n";
exit 0;
