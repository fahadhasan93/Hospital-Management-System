# Hospital Management System

## Overview
The **Hospital Management System** is a simple C-based program designed to manage hospital records, including doctor entries, patient admissions, and consultation status. This system helps track patient details, doctor assignments, and medical records efficiently.

## Features
- **Doctor Management**: Add new doctors and assign them to departments.
- **Patient Admission**: Register new patients with their details.
- **Consultation Tracking**: Categorizes patients into normal and emergency cases.
- **Doctor-Patient Assignment**: Assigns doctors to patients based on availability.
- **Queue Management**: Keeps track of patient queues for each doctor.
- **Deletion of Records**: Marks consultations as complete when a patient is treated.

## Installation & Compilation
To run this project, you need a C compiler installed on your system.

### Steps:
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/Hospital-Management-System.git
   cd Hospital-Management-System
   ```
2. Compile the program using GCC:
   ```sh
   gcc hospital_management.c -o hospital_management
   ```
3. Run the program:
   ```sh
   ./hospital_management
   ```

## Usage
Upon running the program, you will be presented with a menu:
- **1**: Patient Admission
- **2**: New Doctor Entry
- **3**: View Patient Status
- **4**: Exit the system

Follow the prompts to enter doctor and patient details accordingly.

## Code Structure
- `pa_node`: Structure to store patient information.
- `doc_node`: Structure to store doctor details.
- `new_doctor_entry()`: Function to add a new doctor.
- `doctor_find()`: Function to search for a doctor by name or ID.
- `patient_log()`: Displays patient queue for a doctor.
- `delet()`: Removes a patient from the queue after consultation.

## Contribution
1. Fork the repository.
2. Create a new branch:
   ```sh
   git checkout -b feature-name
   ```
3. Make your changes and commit:
   ```sh
   git commit -m "Added new feature"
   ```
4. Push to your fork and submit a Pull Request.

## License
This project is licensed under the MIT License.

## Contact
For any queries, feel free to reach out:
- Email: fahadhasan1511@gmail.com
- GitHub: [fahadhasan93](https://github.com/fahadhasan93)

Happy coding! 🚀

