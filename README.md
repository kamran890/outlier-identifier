# Outlier Identifier

Identify outlier datapoints and replace with caculated fitting.

## Assumptions:

There is an ambiguity in the requirements. I assumed following things.

- When a datapoint is declared outlier, the fitted value is calculated by adding 1 to the last value in output. e.g. with `max_change_rate=3` and input `[1,2,6500,6501,6]`, the output would be `[1,2,3,4,6]`. The value `4` is calculated by adding 1 to previous fitted value i.e. 3.
- The change is measured by comparing the current value of input with the last value in output (which could be same as previous input datapoint or could be fitted one). e.g. in above example, the `6501` is compared with `3` not `6500`.

## Running test cases.

- Compile

```
make
```

- Run tests

```
./test
```
