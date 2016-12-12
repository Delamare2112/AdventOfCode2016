import Text.Printf (printf)
import Data.List (sort)
import Data.List.Split (splitOn)

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
	let realTriangles = [y | y <- triangles, isReal y]

	printf "%d\n" (length realTriangles)
