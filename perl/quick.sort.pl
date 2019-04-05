#!/usr/bin/perl

### Recursively, pick first element as pivot and sort remaining array to its left and right,
### in such a way that all elements lesser than or equal to pivot is on its left and greater are on its right
### till both left and right are exhausted of elements

#@array=(5,3,12,6,4,8,2,7,11,1,4);
@array=(5,3,12,6,4,8,2);
$arraysize=@array;

## Usage: quicksort(low,high);
sub  quicksort
{
  $arguments=@_;
  if($arguments lt 2) { print "Usage quicksort(begin,end)\n"; exit 1;}

  local($low,$high,$pivot,$count,$i,$lidx,$ridx,@left,@right);
  $low=$_[0];
  $high=$_[1];

  $pivot=$array[$low];
  $i=$low;
  $lidx=0;
  $ridx=0;

  while ($i<$high)
  {
    $i++;
    if ($array[$i]<=$pivot)
    {
      $left[$lidx++]=$array[$i]; 
    }
    else
    {
      $right[$ridx++]=$array[$i];
    }
  }
  
  $i=$low;
  for ($count=0;$count<$lidx;$count++) { $array[$i++]=$left[$count]; } 
  $array[$i++]=$pivot;
  for ($count=0;$count<$ridx;$count++) { $array[$i++]=$right[$count]; } 

  print "low=$low; high=$high; pivot=$pivot; left=@left right=@right; array=@array \n";

  if($lidx>0) { print "left side loop!   "; quicksort($low,$low+$lidx-1);}
  if($ridx>0) { print "rite side loop!   "; quicksort($high-($ridx-1),$high);}
}

## MAIN

print "Before QuickSort :@array\n";
quicksort(0,$arraysize-1);
print "After QuickSort :@array\n";

exit 0;
