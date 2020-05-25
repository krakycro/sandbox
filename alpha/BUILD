_COPTS = [
    "/std:c++17",
    "-Ialpha",
]
_HDRS = "head/"
_SRCS = "src/"


cc_library(
    name = "alpha_lib",
    srcs =  glob([_SRCS + "**/*"]),
    hdrs = glob([_HDRS + "**/*"]),
    copts = _COPTS,
)

cc_library(
    name = "alpha_main",
    srcs =  [
        _SRCS + "alpha.cpp",
        _HDRS + "alpha.h",
    ],
    copts = _COPTS,
    deps = [":alpha_lib"],
)

cc_binary(
    name = "alpha",
    srcs =  ["main.cpp"],
    copts = _COPTS,
    linkopts = ["-lpthread"],
    deps = [":alpha_main"],
)