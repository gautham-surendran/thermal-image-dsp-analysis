# Thermal Image and Sensor Data Analysis Using Digital Signal Processing

## 1. Project Overview

This project explores the application of Digital Signal Processing (DSP) techniques for thermal image analysis, sensor data processing and object classification.

The system analyses thermal images obtained from the FLIR dataset to identify potential human and vehicle targets. Thermal images are processed as two-dimensional spatial signals using image enhancement, frequency-domain analysis, spatial filtering and feature extraction techniques.

In parallel, an Arduino-based infrared temperature sensing module using the MLX90614 sensor is implemented to acquire temperature readings. These readings are treated as one-dimensional time-series signals and processed using Finite Impulse Response (FIR) filtering to reduce measurement noise.

The project demonstrates how spatial-domain image processing and time-domain signal processing can be applied together for thermal surveillance and target detection in low-visibility environments.

## 2. Objectives

- Apply Digital Signal Processing techniques to thermal image analysis.
- Analyse thermal images in both spatial and frequency domains.
- Implement two-dimensional Discrete Fourier Transform (2D-DFT) for spatial frequency analysis.
- Apply convolution-based smoothing and edge detection.
- Extract statistical, geometrical and intensity-based image features.
- Implement contour-based object detection and Human/Vehicle classification.
- Acquire and process infrared temperature readings using an Arduino-based MLX90614 sensor.
- Implement FIR filtering for sensor signal smoothing and noise reduction.
- Explore the integration of image-derived features and infrared sensor measurements.

## 3. Technologies and Tools

| Category | Technologies |
|---|---|
| Programming Language | Python |
| Image Processing | OpenCV |
| Numerical Computing | NumPy |
| Data Analysis | Pandas |
| Visualization | Matplotlib |
| Signal Processing | SciPy |
| Machine Learning | Scikit-learn |
| Hardware | Arduino |
| Infrared Sensor | MLX90614 |
| Communication | Serial Communication |

## 4. System Methodology

The proposed system consists of two parallel processing pipelines.

### 4.1 Thermal Image Processing – 2D Signal Analysis

Thermal images are processed through the following stages:

**Image Acquisition**

Thermal images are obtained from a selected subset of the FLIR thermal image dataset.

**Image Preprocessing**

- Grayscale conversion to obtain single-channel image data.
- Resizing to a standard resolution of 240 × 320 pixels.
- Histogram equalization to enhance image contrast.

**Frequency-Domain Analysis**

A two-dimensional Fast Fourier Transform (2D FFT) is applied to the equalized thermal images.

The magnitude spectrum is calculated and visualized to examine the spatial frequency components of the images.

**Spatial Filtering and Edge Detection**

Two convolution-based operations are implemented:

- **Smoothing:** A 5 × 5 averaging kernel is used to reduce pixel-level variations.
- **Edge Detection:** A Sobel-like convolution kernel is used to highlight image boundaries and structural details.

These operations are implemented using the `convolve()` function from SciPy.

**Feature Extraction**

Statistical image features include:

- Mean intensity
- Maximum intensity
- Standard deviation
- Hot-pixel count

Additional contour-based features include:

- Contour area
- Aspect ratio
- Extent
- Solidity
- Perimeter
- Eccentricity
- Average intensity
- Standard intensity deviation
- Hotspot count
- Vertical hotspot ratio

### 4.2 Infrared Sensor Processing – 1D Signal Analysis

An Arduino-based MLX90614 infrared temperature sensor is used to acquire ambient and object temperature readings.

The sensor processing pipeline consists of:

**Data Acquisition**

Temperature readings are collected through serial communication using Python's PySerial library.

**Time-Series Analysis**

The acquired temperature measurements are treated as discrete-time signals.

**FIR Filtering**

A Finite Impulse Response (FIR) low-pass filter is implemented using SciPy.

The filter coefficients are generated using `firwin()`, and filtering is performed using `lfilter()`.

This helps smooth the temperature measurements and reduce transient variations.

Sensor acquisition is optional and can be enabled by configuring the Arduino serial port in the Python implementation.

### 4.3 Object Detection and Classification

Object detection is performed using intensity-based thresholding and contour extraction.

The processing stages include:

1. Thresholding based on the 85th percentile of image intensity.
2. Morphological closing to refine detected regions.
3. External contour extraction.
4. Geometrical and intensity-based feature extraction.
5. Classification of detected regions.

The current implementation supports three heuristic classification outcomes:

- Human
- Vehicle
- Unknown

A scoring-based heuristic classifier uses features such as aspect ratio, extent, solidity, eccentricity, hotspot count and intensity variation.

An optional Random Forest classifier is also implemented using Scikit-learn. It can be trained when a labelled feature dataset containing the required features and classification labels is available. Otherwise, the system falls back to heuristic classification.

### 4.4 Image and Sensor Data Integration

The proposed methodology explores combining:

- Spatial information obtained from thermal image processing.
- Temperature measurements obtained from the MLX90614 sensor.

The implementation includes a temperature-based confirmation condition that compares detected-region average image intensity with the measured object temperature. When the difference is within a specified tolerance, the detection confidence score is increased.

**Note:** Sensor acquisition is disabled by default in the current configuration. This integration can be enabled when the Arduino hardware is connected and the serial port is configured. The image-processing pipeline operates independently.

## 5. Results and Outputs

The project produces visualizations and numerical outputs at different processing stages.

### Image Processing Visualizations

- Original thermal image
- Histogram-equalized image
- 2D FFT magnitude spectrum
- Smoothed thermal image
- Edge-detected image
- Annotated image with detected objects and classification labels

### Numerical Outputs

Image features and object detection results are exported as CSV files.

The generated outputs include:

- Statistical image features
- Contour-based geometrical features
- Object classification labels
- Detection confidence scores
- Bounding-box coordinates
- Sensor temperature information, when available

## 6. Dataset

The thermal images used in this project were manually selected from the following Kaggle dataset:

**Thermal Image Dataset for Object Classification**

Contributor: Breejesh Dhar

Dataset source:

https://www.kaggle.com/datasets/breejeshdhar/thermal-image-dataset-for-object-classification

Only a selected subset of images was used for experimentation. The complete dataset is not included in this repository.

Users should refer to the original Kaggle dataset page for the applicable licensing and usage conditions.

## 7. Repository Structure

```text
thermal-image-dsp-analysis/
│
├── PROJECT.py
├── requirements.txt
├── README.md
├── .gitignore
│
├── sketch_aug17a/
│   └── sketch_aug17a.ino
│
└── sketch_sep14a/
    └── TEMPERATURE_ACQUIRE.ino
```

**Additional directories created during execution:**

- `New folder/` – Input directory containing thermal images.
- `output/` – Directory containing generated object detection results.

These directories are excluded from the Git repository.

## 8. Installation and Execution

### Prerequisites

- Python 3.11 or compatible Python version.
- Git.
- Arduino and MLX90614 sensor (only if sensor acquisition is required).

### Step 1: Clone the Repository

```bash
git clone https://github.com/gautham-surendran/thermal-image-dsp-analysis.git
cd thermal-image-dsp-analysis
```

### Step 2: Create a Virtual Environment

```bash
python -m venv .venv
```

Activate the environment.

**Windows PowerShell:**

```powershell
.venv\Scripts\Activate.ps1
```

**Git Bash:**

```bash
source .venv/Scripts/activate
```

**Linux/macOS:**

```bash
source .venv/bin/activate
```

### Step 3: Install Dependencies

```bash
pip install -r requirements.txt
```

### Step 4: Add Thermal Images

Create a directory named `New folder` in the project root.

Place the thermal images you want to process inside this directory.

Supported image formats:

- JPG
- JPEG
- PNG

### Step 5: Run the Implementation

```bash
python PROJECT.py
```

The program processes the available thermal images, displays the processing visualizations and saves the detection results in the `output` directory.

## 9. Limitations

- The implementation processes offline thermal image datasets rather than live thermal camera streams.
- Object classification relies primarily on heuristic rules unless a suitable labelled training dataset is supplied.
- Classification performance depends on image quality, dataset diversity and object characteristics.
- The MLX90614 provides point-based temperature measurements rather than a complete spatial temperature map.
- Real-time video processing and continuous sensor-image synchronization are not implemented in the current default configuration.
- The comparison between image intensity and sensor temperature requires appropriate calibration for physically meaningful temperature correlation.

## 10. Future Improvements

Potential extensions include:

- Integration with a physical FLIR thermal camera.
- Real-time thermal video processing.
- Improved object classification using CNN- or YOLO-based approaches.
- More robust sensor-image synchronization and temperature calibration.
- Performance evaluation using a larger labelled thermal image dataset.
- Enhanced visualization of spatial and temporal thermal information.

## 11. Conclusion

This project demonstrates the application of Digital Signal Processing techniques to thermal image analysis and infrared sensor data processing.

By combining two-dimensional frequency-domain analysis, convolution-based spatial filtering, statistical feature extraction, contour-based object detection and one-dimensional FIR filtering, the project explores a DSP-based approach to thermal target analysis.

The implementation provides practical experience in applying signal processing concepts using Python libraries and integrating software-based image analysis with an Arduino-based infrared sensing system.

The project establishes a foundation for further development of thermal imaging applications in surveillance, target detection and low-visibility monitoring.