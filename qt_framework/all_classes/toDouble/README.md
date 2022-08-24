# toDouble

Here are comparison of different variants of converting QString to double.

Results in seconds:

|PDNTNCL|PDNTNCR|PDNCL|PDNCR|PDSVL|CL|CR|NCL|NCR|
|---|---|---|---|---|---|---|---|---|
|1.738|4.93|1.786|4.958|1.765|1.385|6.657|1.254|4.947|
|1.74|4.941|1.782|4.945|1.754|1.377|6.735|1.259|4.929|
|1.741|4.91|1.772|4.923|1.751|1.374|8.113|1.882|7.378|
|2.609|7.348|2.658|7.342|2.629|2.065|9.97|1.883|7.373|
|2.603|7.348|2.663|7.374|2.621|2.043|10.088|1.876|7.359|
|2.609|7.365|2.659|7.365|2.631|2.059|9.957|1.885|7.371|
|2.61|7.364|2.661|7.358|2.635|2.067|9.992|1.872|7.378|
|2.591|7.338|2.653|7.36|2.63|2.063|9.984|1.886|7.337|
|2.597|7.342|2.657|7.365|2.634|2.042|10.08|1.871|7.376|
|2.609|7.349|2.665|5.502|1.937|1.991|9.453|1.811|7.103|
|---|---|---|---|---|---|---|---|---|
|2.3447|6.6235|2.3956|6.4492|2.2987|1.8466|9.1029|1.7479|6.8551|

Conclusions:

- [QString::toDouble()](https://doc.qt.io/qt-6/qstring.html#toDouble) works much slower than [QLocale::toDouble()](https://doc.qt.io/qt-6/qlocale.html#toDouble)
- Choice between reference and value in arguments is less significant (in terms of impact on speed)
- Using several locales is less significant (in terms of impact on speed)
- Using [QStringView](https://doc.qt.io/qt-6/qstringview.html) is less significant (in terms of impact on speed)
- Exceptions don't affect much on speed of execution.
