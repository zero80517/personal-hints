# for-loop

This project has example of using ```pthread``` for ```for``` loop.
Comparison of speed for [intel core i7](https://ark.intel.com/content/www/ru/ru/ark/products/134906/intel-core-i78750h-processor-9m-cache-up-to-4-10-ghz.html) (only 1 launch was used):

|Length of arrays| time, s (1 thread)      | time, s (12 threads) |speedup, x|
|---| ---        |    ---   |---|
|6291456| 1.419   | 0.195        |7.276923077|
|12582912| 2.835   | 0.375        |7.56|
|25165824| 5.669   | 0.742        |7.640161725|
|50331648| 11.327      | 1.314       |8.620243531|
