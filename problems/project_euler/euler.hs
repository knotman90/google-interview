module Main where

import Data.Char
import Data.List

intToList 0 = []
intToList a = ( intToDigit (fromIntegral l)) : intToList r
    where
        l = a `mod` 10
        r = a `div` 10


isGood :: String -> Bool
isGood  = (== ['1'..'9'])

--check :: Integer -> Integer -> Integer -> [(Integer , Integer, Integer)]
--check :: (Integral a)=> a -> a -> a -> [(a,a,a)]
check e = [ (c)  | a<-[alower..aupper] , b<-[10^blower..10^bupper] , let c=a*b, 
 (isGood $ list a b c)] 
    where
        alower = 10^e
        aupper = 10^(e+1)-1
        ee     = e+1
        blower = div (9-2*ee) 2  
        bupper = (blower+1)
        list a b  c=  sort ((intToList a)++ (intToList b) ++ (intToList c))

isPalindrome l = l == (reverse l)

toBinaryString 0 = []
toBinaryString n = (intToDigit r) : ( toBinaryString q)
    where
         r = n `mod` 2
         q = n `div` 2

goodN n = dec && bin 
    where 
        bin = isPalindrome $ toBinaryString (fromInteger n) 
        dec = isPalindrome $ intToList (fromInteger n)

solve45 :: Int -> [( Int, Int ) ]
solve45 b =  [ (c, length g) |  g@(c:_) <-  group $ sort ((take b t)++(take b p)++(take b h)), let ln = length g, ln==3]
    where
        t = [ div (n*(n+1)) 2 | n<-[1..]]
        p = [ div (n*(3*n-1)) 2 | n<-[1..]]
        h = [ (n*(2*n-1))  | n<-[1..]]


getDiagonals [] _ _ = []
getDiagonals (x:xs) it n = x : (getDiagonals (drop nit xs) nit nn)
    where 
        nn  = (mod (n+1) 4)
        nit = if (nn)==0 then (it+2) else it 

isPrime :: Integer -> Bool
isPrime 2 = True
isPrime n = null ( divisors n)
    where
        divisors n = [ k | k<-[2..ceiling(sqrt(fromIntegral n))], (mod n k)==0 ]


      
primesInf = [k | k<-[3,5..] , isPrime k]
diagonals = getDiagonals [3..] 1 0
ratio l = (fromIntegral overlap )/((2*(fromIntegral l))-1)
    where
        diagonal = takeWhile (<=l^2) diagonals
        overlap = length [n | n<-diagonal , isPrime n]


mainsprialprimes = do
    s<- getLine
    putStrLn $ show $ [(i,ratio i) | i<-[20001,20003..35001]]

--n/phi(n) minimize phi to get this ratio high. phi(n) is small when the number of 
--non-coprime number is high. The #that shared divisors with more numbers small then itself
--is the one which factorization includes the most primes less then it and which product is less tha 10^6
mainDontRemember = putStrLn $ show $ product  [n | n<-[1..18], isPrime n] 



solve80 = sum [(nhun 1 n) | n<-[2..99],  not (is_square n)]
    where
     nhun c n = sum $ map digitToInt $ take 100  $ reverse (intToList (mysqrt (5*n) 5 1 2000))

is_square n = sq * sq == n
    where sq = floor $ sqrt $ (fromIntegral n::Double)

mysqrt :: Integer -> Integer -> Integer -> Integer-> Integer 
mysqrt a b i limit
    | i == limit = b 
    | a >= b    =  (mysqrt (a-b) (b+10) (i+1) limit)
    | otherwise =  (mysqrt(a*100) ((100*(div b 10)) +5) (i+1) limit)


main = putStrLn $ show $ solve80


main40 = do
    let a=( concat [reverse .intToList $ n | n<-[1..]]) 
    putStrLn $ show $ foldr (\x acc -> acc*(digitToInt x)) 1 [a!!(-1+10^n) | n<-[0,1,2,3,4,5,6]]
main36 = putStrLn (show $ sum $ [n | n<-[0..10^6], goodN n])
main32 = putStrLn (show $sum $ nub $  concat  [check i | i<-[0..3]])
