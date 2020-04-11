_COPTS = [
    "-std=c++17",
]
_HDRS = "headers/"
_SRCS = "srcs/"


cc_library(
    name = "alpha_lib",
    srcs =  glob([_HDRS + "**/*"]),
    hdrs = glob([_HDRS + "**/*.h"]),
    copts = _COPTS,
    strip_include_prefix  = _HDRS,
)

cc_library(
    name = "alpha_main",
    srcs =  [
        _SRCS + "alpha.cpp",
        _HDRS + "alpha.h",
    ],
    hdrs = [_HDRS + "alpha.h"],
    copts = _COPTS,
    strip_include_prefix  = _HDRS,
    deps = [
        ":alpha_lib",
    ],
)

cc_binary(
    name = "alpha",
    srcs =  [
        "main.cpp",
    ],
    copts = _COPTS,
    deps = [
        ":alpha_main",
    ],
)