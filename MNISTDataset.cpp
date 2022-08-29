//
// Created by waford on 8/29/22.
//

#include "MNISTDataset.hpp"

#include <curl/curl.h>
#include <unistd.h>
#include <sys/stat.h>

MNISTDataset::MNISTDataset(std::string name, std::string image_url, std::string label_url) {
    touchDatasetDirectory(name);
    CURL *curl = curl_easy_init();
}

void MNISTDataset::touchDatasetDirectory(std::string name) {
    struct stat dir_stat;
    if(!stat(kDatasetDirectory, dir_stat)) {

    }
}