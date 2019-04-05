###
#Euclidian Algorithm
#GCD (24,9)
# 24 = 9 * 2 + 6
# 09 = 6 * 1 + 3
# 06 = 3 * 2 + 0
# Stop at reminder 0
# The last divsor (3) is the GCD.
###

class math:
    def __init__(self):
        print "Initialized an object"

    def gcd_recurse(self,number,divisor):
        print "number: " + str(number) + "; divisor: " + str(divisor)

        if number==0 or divisor==0:
            return "N/A"

        if number<0 or divisor<0:
            return 1

        # Ensure number>divsor always
        if (number<divisor):
            temp=number
            number=divisor
            divisor=temp

        #quotient = int(number/divisor)
        reminder = number%divisor
        #print "quotient: " + str(quotient) + "; reminder: " + str(reminder)

        if (reminder == 0):
            print "GCD is: " + str(divisor)
            return divisor
        else:
            return self.gcd_recurse(divisor,reminder)

    def gcd_interate(self,number,divisor):
        if number==0 or divisor==0:
            return "N/A"

        if number<0 or divisor<0:
            return 1

        # Ensure number>divsor always
        if (number<divisor):
            temp=number
            number=divisor
            divisor=temp

        quotient = int(number/divisor)
        reminder = number%divisor

        while (reminder > 0):
            #print "number: " + str(number) + "; divisor: " + str(divisor)
            #print "quotient: " + str(quotient) + "; reminder: " + str(reminder)
            number = divisor
            divisor = reminder
            quotient = int(number/divisor)
            reminder = number%divisor

        print "GCD is: " + str(divisor)
        return divisor


if __name__ == '__main__':
    mathObject = math()
    print "gcd(24,9) = " + str(mathObject.gcd_interate(24,9))
    print "gcd(369,252) = " + str(mathObject.gcd_recurse(369,252))
    #print "gcd(1,1) = " + str(mathObject.gcd(1,1))
    #print "gcd(1,0) = " + str(mathObject.gcd(1,0))
    #print "gcd(0,1) = " + str(mathObject.gcd(0,1))
    #print "gcd(-9,4) = " + str(mathObject.gcd(-9,4))
    #print "gcd(18,-8) = " + str(mathObject.gcd(18,-8))
    #print "gcd(-9,-3) = " + str(mathObject.gcd(-9,-3))

