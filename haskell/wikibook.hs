module Exercices where

--  RECURSION AND LIST I
factN 0 = 1
factN n = factN (n-1) *n

fact 0 = 1
fact n = product [1..n]

doublefactorial 0 = 1
doublefactorial 1 = 1
doublefactorial n = doublefactorial (n-2) * n

plusOne = (+)1 
addition x 0 = x
addition x y = addition (plusOne x) (y-1)

power _ 0 = 1
power 0 _ = 0
power x y = x * power x (y-1)

power2 _ 0 = 1
power2 0 _ = 0
power2 x y  
    | y `mod`2 == 0 = let r = power2 x (div y 2) in r*r
    | otherwise     = x*power2 x (y-1)

log2' 1 = 0
log2' n = go n 1 2
    where
    go n l p 
        | p > n = l-1
        |otherwise = go n (l+1) (2*p)

    


replicate' :: Int -> a -> [a]
replicate' 0 _ = []
replicate' n e = e: replicate' (n-1) e

(!!!) :: [a] -> Int -> a
(!!!) (x:_) 0 = x
(!!!) [] _ = error "Index too large"
(!!!) (_:xs) n = (!!!) xs (n-1)

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (x:xs) (y:ys) = (,)x y : zip' xs ys

--lengthacc :: [a] -> Int
lengthacc xs = go xs 0
    where 
        go [] c = c
        go (x:xs) c= go xs (c+1)

-- LIST II  
multiplyList :: (Num a)=> [a] ->  a-> [a]
multiplyList [] _ = []
multiplyList (x:xs) n = (n*x) : multiplyList xs n

takeInt :: [a] -> Int -> [a]
takeInt _ 0 = []
takeInt [] _ = []
takeInt (x:xs) n = x: takeInt xs  (n-1)

dropInt :: [a] -> Int -> [a]
dropInt xs 0 = xs
dropInt [] _ = []
dropInt (x:xs) n = dropInt xs (n-1)

sumInt :: (Num a) => [a] -> a
sumInt [] = 0
sumInt (x:xs) = x+ sumInt xs

sumInt' :: (Num a ) => [a] -> a
sumInt' = foldr (+) 0

scanSum :: (Num a ) => [a] -> [a]
scanSum xs = go xs 0
    where
    go [] _ = []
    go (x:xs) n = let p = n+x in p : go xs p

diffs :: (Num a) => [a] -> [a]
diffs [] = []
diffs (x:[]) = []
diffs (x:y:xs) = (y-x) : diffs (y:xs)

mymap :: (a -> b) -> [a] -> [b]
mymap _ [] = []
mymap f (x:xs) = (f x) : mymap f xs


negateL :: (Num a )=>[a] -> [a]
negateL = map negate

divisors :: ( Integral a ) => a -> [a]
divisors p = [ k | k<-[1..p], (mod p k) == 0 ]

divisorsL :: (Integral a) => [a] -> [[a]]
divisorsL = map divisors

negateLL :: (Num a) => [[a]] -> [[a]]
negateLL = map negateL 

countEq ::(Eq a)=> a-> [a] -> Int
countEq _ [] = 0
countEq c (x:xs) 
    | c == x = 1 + countEq c xs 
    |otherwise = 0

    
rleE ::(Eq b)=> [b] -> [(Int,b)]
rleE [] = []
rleE l@(x:xs) = (c , x) : (rleE (dropInt l c))
        where c = countEq x l

rleD :: [(Int,b)] -> [b]
rleD [] = []
rleD ((x,y):xs) = (replicate x y) ++ rleD xs 
