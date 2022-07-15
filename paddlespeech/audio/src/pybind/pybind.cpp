// Copyright (c) 2017 Facebook Inc. (Soumith Chintala), All rights reserved.
// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.

#include "paddlespeech/audio/src/pybind/kaldi/kaldi_feature.h"
#include "paddlespeech/audio/src/pybind/sox/io.h"
#include "paddlespeech/audio/third_party/kaldi/feat/feature-fbank.h"

PYBIND11_MODULE(_paddleaudio, m) {
#ifdef INCLUDE_SOX
    m.def("get_info_file",
          &paddleaudio::sox_io::get_info_file,
          "Get metadata of audio file.");
    m.def("get_info_fileobj",
          &paddleaudio::sox_io::get_info_fileobj,
          "Get metadata of audio in file object.");
#endif

#ifdef INCLUDE_KALDI
    m.def("ComputeFbank", &paddleaudio::kaldi::ComputeFbank, "compute fbank");
    py::class_<kaldi::PitchExtractionOptions>(m, "PitchExtractionOptions")
        .def(py::init<>())
        .def_readwrite("samp_freq", &kaldi::PitchExtractionOptions::samp_freq)
        .def_readwrite("frame_shift_ms", &kaldi::PitchExtractionOptions::frame_shift_ms)
        .def_readwrite("frame_length_ms", &kaldi::PitchExtractionOptions::frame_length_ms)
        .def_readwrite("preemph_coeff", &kaldi::PitchExtractionOptions::preemph_coeff)
        .def_readwrite("min_f0", &kaldi::PitchExtractionOptions::min_f0)
        .def_readwrite("max_f0", &kaldi::PitchExtractionOptions::max_f0)
        .def_readwrite("soft_min_f0", &kaldi::PitchExtractionOptions::soft_min_f0)
        .def_readwrite("penalty_factor", &kaldi::PitchExtractionOptions::penalty_factor)
        .def_readwrite("lowpass_cutoff", &kaldi::PitchExtractionOptions::lowpass_cutoff)
        .def_readwrite("resample_freq", &kaldi::PitchExtractionOptions::resample_freq)
        .def_readwrite("delta_pitch", &kaldi::PitchExtractionOptions::delta_pitch)
        .def_readwrite("nccf_ballast", &kaldi::PitchExtractionOptions::nccf_ballast)
        .def_readwrite("lowpass_filter_width", &kaldi::PitchExtractionOptions::lowpass_filter_width)
        .def_readwrite("upsample_filter_width", &kaldi::PitchExtractionOptions::upsample_filter_width)
        .def_readwrite("max_frames_latency", &kaldi::PitchExtractionOptions::max_frames_latency)
        .def_readwrite("frames_per_chunk", &kaldi::PitchExtractionOptions::frames_per_chunk)
        .def_readwrite("simulate_first_pass_online", &kaldi::PitchExtractionOptions::simulate_first_pass_online)
        .def_readwrite("recompute_frame", &kaldi::PitchExtractionOptions::recompute_frame)
        .def_readwrite("nccf_ballast_online", &kaldi::PitchExtractionOptions::nccf_ballast_online)
        .def_readwrite("snip_edges", &kaldi::PitchExtractionOptions::snip_edges);
    m.def("ComputeKaldiPitch", &paddleaudio::kaldi::ComputeKaldiPitch, "compute kaldi pitch");
    py::class_<kaldi::FrameExtractionOptions>(m, "FrameExtractionOptions")
        .def(py::init<>())            
        .def_readwrite("samp_freq", &kaldi::FrameExtractionOptions::samp_freq)
        .def_readwrite("frame_shift_ms", &kaldi::FrameExtractionOptions::frame_shift_ms)            
        .def_readwrite("frame_length_ms", &kaldi::FrameExtractionOptions::frame_length_ms)
        .def_readwrite("dither", &kaldi::FrameExtractionOptions::dither)            
        .def_readwrite("preemph_coeff", &kaldi::FrameExtractionOptions::preemph_coeff)            
        .def_readwrite("remove_dc_offset", &kaldi::FrameExtractionOptions::remove_dc_offset)            
        .def_readwrite("window_type", &kaldi::FrameExtractionOptions::window_type)
        .def_readwrite("round_to_power_of_two", &kaldi::FrameExtractionOptions::round_to_power_of_two)           
        .def_readwrite("blackman_coeff", &kaldi::FrameExtractionOptions::blackman_coeff)          
        .def_readwrite("snip_edges", &kaldi::FrameExtractionOptions::snip_edges)
        .def_readwrite("allow_downsample", &kaldi::FrameExtractionOptions::allow_downsample)
        .def_readwrite("allow_upsample", &kaldi::FrameExtractionOptions::allow_upsample)
        .def_readwrite("max_feature_vectors", &kaldi::FrameExtractionOptions::max_feature_vectors);
    py::class_<kaldi::MelBanksOptions>(m, "MelBanksOptions")
        .def(py::init<>())
        .def_readwrite("num_bins", &kaldi::MelBanksOptions::num_bins)
        .def_readwrite("low_freq", &kaldi::MelBanksOptions::low_freq)
        .def_readwrite("high_freq", &kaldi::MelBanksOptions::high_freq)
        .def_readwrite("vtln_low", &kaldi::MelBanksOptions::vtln_low)
        .def_readwrite("vtln_high", &kaldi::MelBanksOptions::vtln_high)
        .def_readwrite("debug_mel", &kaldi::MelBanksOptions::debug_mel)
        .def_readwrite("htk_mode", &kaldi::MelBanksOptions::htk_mode);

    py::class_<paddleaudio::kaldi::FbankOptions>(m, "FbankOptions")
        .def(py::init<>())
        .def_readwrite("use_energy", &paddleaudio::kaldi::FbankOptions::use_energy)
        .def_readwrite("energy_floor", &paddleaudio::kaldi::FbankOptions::energy_floor)
        .def_readwrite("raw_energy", &paddleaudio::kaldi::FbankOptions::raw_energy)
        .def_readwrite("htk_compat", &paddleaudio::kaldi::FbankOptions::htk_compat)
        .def_readwrite("use_log_fbank", &paddleaudio::kaldi::FbankOptions::use_log_fbank)
        .def_readwrite("use_power", &paddleaudio::kaldi::FbankOptions::use_power);
#endif

}