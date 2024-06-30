fibList xs = if next > 4000000 then xs else fibList ( xs ++ [next] ) where next = last xs + last (init xs)

euler2 = sum [ x | x <- fibList [0,1], x `mod` 2 == 0 ]
