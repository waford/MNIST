//
// Created by waford on 8/29/22.
//

#ifndef EIGEN_TEST_MNISTDATASET_HPP
#define EIGEN_TEST_MNISTDATASET_HPP

#include <vector>
#include <string>

#include <curl/curl.h>
#include "MNISTImage.hpp"

class MNISTDataset {
    public:
        MNISTDataset(std::string datasetName, std::string imageURL, std::string labelURL);
    private:
        inline static const std::string kDatasetDirectory = "datasets";
        std::string datasetName;
        std::string directoryPath;
        std::string imageURL;
        std::string labelURL;
        std::vector<MNISTImage> MNISTImages;

        void init();
        void touchDatasetDirectory(std::string name);
        void curlURL(CURL *curl, std::string filename, std::string url);
        
        std::string buildFilename(std::string url);
};

#endif //EIGEN_TEST_MNISTDATASET_HPP
