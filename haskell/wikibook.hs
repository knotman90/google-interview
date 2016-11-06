module Exercices where

import Data.List

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

--LIST III
--
myfoldr :: (a -> b -> b) -> b-> [a] -> b
myfoldr _ acc [] = acc
myfoldr f acc (x:xs) = f x (myfoldr f acc xs)

myfoldr1 :: (b -> b -> b) -> [b] -> b
myfoldr1 _ [] = error "Empty list"
myfoldr1 f (x:xs)  = myfoldr f x xs

myfoldl :: (b -> a -> b) -> b -> [a] -> b
myfoldl _ acc [] = acc
myfoldl f acc (x:xs) = myfoldl f (f acc x) xs


myfoldl1 :: (b -> b -> b) ->  [b] -> b
myfoldl1 _ [] = error "empty List"
myfoldl1 f (x:xs) = myfoldl f x xs

mapfold :: (a -> b) -> [a] -> [b]
mapfold f      = foldr (\x acc -> f x : acc) []

myand :: [Bool] -> Bool
myand [] = True
myand (x:xs) = x && myand xs

myor :: [Bool] -> Bool
myor [] = False
myor (x:xs) = x || myor xs

myandfold :: [Bool] -> Bool
myandfold = myfoldr (&&) True

myorfold :: [Bool] -> Bool
myorfold = myfoldr (||) False

mymaximumfold :: Ord a => [a] -> a
mymaximumfold = myfoldr1 max

myminimumfold :: Ord a => [a] -> a
myminimumfold = myfoldr1 min

myreversefold :: [a] -> [a]
myreversefold = foldr (\x acc -> acc ++ [x]) []

myreversefold2 :: [a]-> [a]
myreversefold2 = foldl (\acc x -> x:acc) []

myscanl :: (a -> b -> a) -> a -> [b] -> [a]
myscanl f acc [] = [acc]
myscanl f acc  (x:xs) = let p = f acc x in p : (myscanl f p xs)

myscanr :: (a -> b -> b) -> b -> [a] -> [b]
myscanr _ acc []      = [acc]
myscanr f acc (x:xs)  = let acc1@(y:_) = myscanr f acc xs in f x y : acc1

myscanlfoldl :: (a -> b -> a) -> a -> [b] -> [a]
myscanlfoldl f acc = foldl (\acc1@[y,_] x ->  acc1 ++ [f y x ]) [acc]

myscanrfoldr :: (a -> b -> b) -> b ->[a] -> [b]
myscanrfoldr f acc = foldr (\x acc1@(y:_) -> f x y : acc1 ) [acc]

isEven :: (Integral a) => a -> Bool
isEven x = mod x 2 == 0

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter _ [] = []
myfilter f (x:xs)
  | f x = x : rest
  | otherwise = rest
    where
      rest = myfilter f xs

myfilterfold :: (a -> Bool) -> [a] -> [a]
myfilterfold f = foldr (\x acc -> if f x then x : acc else acc) []

myfilterComp :: (a -> Bool) -> [a] -> [a]
myfilterComp f xs = [p | p <- xs, f p]

retainEvenComp :: (Integral a) => [a] -> [a]
retainEvenComp xs = [ p | p <-xs , isEven p]

retainEvenFilter :: (Integral a) => [a] -> [a]
retainEvenFilter = filter isEven

returnDivisible :: Int -> [Int] -> [Int]
returnDivisible n = filter (\x -> mod x n == 0)

choosingTails :: (a -> Bool) -> [[a]] -> [[a]]
choosingTails headFilter xs = [ xxs | (x:xxs)<- xs , headFilter x]

mapComp :: (a -> b) -> [a] -> [b]
mapComp f xs = [f x | x <- xs]

doubleOfFirstForEvenSecond :: (Integral a) => [(a,a)] -> [(a,a)]
doubleOfFirstForEvenSecond =  map (\(x,y) -> (2*x,y)) . filter (\(_,x) ->isEven x)

--TYPE DECLARATIONù
data Date = Date Int Int Int

type Name = String
type Couple = (Name, Name)
data Anniversary = Birthday Name Date | Wedding Couple Date

instance Show Anniversary where
  show (Birthday name date) = "Birthday of "++ show name ++ " on " ++ show date
  show (Wedding (n,n1) date) = "Wedding of " ++ show n ++ " and " ++ show n1 ++" on " ++ show date

instance Show Date  where
  show d = showDate d

showDate :: Date -> String
showDate (Date y m d) =  show y ++ "-" ++ show m ++ "-" ++show d

h ::Int -> Bool
h 1 = True
h _ = False

--Boolean values are first letter capital string. They are type constructor! True and False Boolean is declared as follow
--data Bool = True | False

--set difference
(\\\) :: (Eq a ) => [a] -> [a] ->[a]
(\\\) xs ys = foldr (\x acc -> delete x acc) xs ys
