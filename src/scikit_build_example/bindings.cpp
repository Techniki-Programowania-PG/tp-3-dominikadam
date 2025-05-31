#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>

#include "signals.hpp"
#include "filter.hpp"

namespace py = pybind11;

PYBIND11_MODULE(scikit_build_example, m) {
    m.doc() = "Signal processing module including generators, DFT and filtering";

    m.def("generate_sin", &generate_sin, "Generate sine wave",
        py::arg("frequency"), py::arg("amplitude"), py::arg("phase"), py::arg("sampling_rate"), py::arg("samples"));

    m.def("generate_cos", &generate_cos, "Generate cosine wave",
        py::arg("frequency"), py::arg("amplitude"), py::arg("phase"), py::arg("sampling_rate"), py::arg("samples"));

    m.def("generate_square", &generate_square, "Generate square wave",
        py::arg("frequency"), py::arg("amplitude"), py::arg("sampling_rate"), py::arg("samples"));

    m.def("generate_sawtooth", &generate_sawtooth, "Generate sawtooth wave",
        py::arg("frequency"), py::arg("amplitude"), py::arg("sampling_rate"), py::arg("samples"));

    m.def("dft", &dft, "Discrete Fourier Transform", py::arg("signal"));
    m.def("idft", &idft, "Inverse Discrete Fourier Transform", py::arg("spectrum"));

    m.def("filter_1d", &filter_1d, "Apply 1D filter to a signal");
    m.def("filter_2d", &filter_2d, "Apply 2D filter to an image");
    m.def("plot_signal", [](const std::vector<double>& s) {
        plot_signal(s);
        }, "Plot signal using matplot++");


}
