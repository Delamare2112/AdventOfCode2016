import Text.Printf (printf)
import Data.List (sort)
import Data.List.Split (splitOn)
import Data.List.Split (chunksOf)

strsToInts :: [[String]] -> [[Int]]
strsToInts st = [ [ (read x :: Int) | x <- y] | y <- st]

isReal :: [Int] -> Bool
isReal x = (s !! 0) + (s !! 1) > (s !! 2) 
	where s = sort x

removeEmptys :: [[[Char]]] -> [[[Char]]]
removeEmptys xs = [ [ x | x <- number, not (x == "")] | number <- xs]

main :: IO()
main = do
	datad <- readFile "input.txt"
	let raw = splitOn "\n" datad
	let dirty = map (splitOn " ") raw
	let clean = removeEmptys dirty
	let triangles = strsToInts clean

	let allTriangleValues = [x !! 0 | x <- triangles] ++ [x !! 1 | x <- triangles] ++ [x !! 2 | x <- triangles]
	let newTriangles = chunksOf 3 allTriangleValues

	let realTrianglesHorizontally = [y | y <- triangles, isReal y]
	let realTrianglesVertically = [y | y <- newTriangles, isReal y]

	printf "Horizontally: %d\nVertically: %d\n" (length realTrianglesHorizontally) (length realTrianglesVertically)
