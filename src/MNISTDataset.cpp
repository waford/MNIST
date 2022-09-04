//
// Created by waford on 8/29/22.
//

#include "MNISTDataset.hpp"

#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <stdio.h>
#include <unistd.h>

namespace fs = std::filesystem;

MNISTDataset::MNISTDataset(std::string name):
    datasetName(name),
    directoryPath(kDatasetDirectory + "/" + datasetName)
{   
    init();
}

void MNISTDataset::init() {
    for(const auto & file : fs::directory_iterator(directoryPath)) {
        std::string filename = file.path().filename();
        std::cout << "filename: " << filename << std::endl;
        if(filename.find("image") != std::string::npos && !image_stream.is_open()) {
            image_stream.open(file.path(), std::ifstream::in | std::ifstream::binary);
        } else if (filename.find("label") != std::string::npos && !label_stream.is_open()) {
            label_stream.open(file.path(), std::ifstream::in | std::ifstream::binary);
        }
    }
}

void MNISTDataset::parseData() {
    int32_t image_header[4];
    int32_t label_header[2];
    readBigEndianStream(image_stream, image_header, 4);
    readBigEndianStream(label_stream, label_header, 2);

    // Check magic numbers to make sure the file is the one we expect
    assert(image_header[0] == kImageMagicNumber);
    assert(label_header[0] == kLabelMagicNumber);

    // Check that the image and label files have the same number of elements
    assert(image_header[1] == label_header[1]);

    assert(image_header[2] == 28);
    assert(image_header[3] == 28);

    uint8_t label;
    uint8_t pixel_data[28*28];
    for(int i = 0; i < image_header[1]; i++) {
        label_stream.read((char *) &label, 1*sizeof(uint8_t));
        image_stream.read((char *) pixel_data, 28*28*sizeof(uint8_t));
        MNISTImages.emplace_back(label, pixel_data);
    }
    
    // close streams
    image_stream.close();
    label_stream.close();
}

void MNISTDataset::drawLabeledImages(int cap) {
    cap = std::max<int>(cap, MNISTImages.size());
    for(int i = 0; i < cap; i++) {
        MNISTImages[i].drawImage("bmp/" + std::to_string(i) + "-" +std::to_string(MNISTImages[i].label()) + ".bmp");
    }
}

void MNISTDataset::readBigEndianStream(std::ifstream &stream, int32_t * data, size_t num_ints) {
    stream.read((char *) data, num_ints * sizeof(int32_t));
    for(int i = 0; i < num_ints; i++) {
        swapEndiness(data[i]);
    }
}
