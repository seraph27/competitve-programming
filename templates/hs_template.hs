import qualified Data.ByteString.Char8 as BS
import Data.Maybe (fromJust)
import qualified Data.Vector.Unboxed as VU
import Control.Monad
import Data.List

readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

readInts :: IO [Int]
readInts = map readInt . BS.words <$> BS.getLine

main :: IO ()
main = do
    input <- BS.getContents
    let nums = map readInt (BS.words input)
    print ( solve nums )

solve :: [Int] -> Int
solve xs = foldl' (+) 0 xs
