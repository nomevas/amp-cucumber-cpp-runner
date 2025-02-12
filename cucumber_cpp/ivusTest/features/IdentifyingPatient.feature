Feature: Identifying the patient
  In order to ensure that the clinical user is performing the procedure with
  the correct study in progress, they need to be able to confirm the name,
  identification number, date of birth and age of the patient.

  @IVUS.CV.Setup.DisplayPatientInformation
  Rule: Display patient information when a study is selected
  The application shall display the following patient information:

    * Study state for studies in progress
    * Family name
    * First name
    * Middle name(s)
    * Patient ID
    * Date of birth
    * Age

  The age of the patient is formatted according to the following rules:

    * When the age is less than or equal to thirty days, then the age will be displayed in days, otherwise
    * When the age is less than or equal to twelve weeks, then the age will be displayed in weeks, otherwise
    * When the age is less than or equal to twenty four months, the age will be displayed in months, otherwise
    * The age will be displayed in years

  The application shall truncate the patient information when it does not fit the
  allocated user interface in the following order:

    * Middle name shall be truncated completely, from the end, on a letter-by-letter basis, and then
    * First name shall be truncated completely, from the end, on a letter-by-letter basis, and then
    * Last name shall be truncated completely, from the end, on a letter-by-letter basis, and then
    * Date of birth shall be truncated completely, at once, and then
    * Patient ID shall be truncated completely, from the beginning, on a number-by-number

  Background:
    Given the following studies
      | Study ID | Family name | First name | Middle name | Patient ID     | Date of birth |
      | 1        | Higgins     | Kate       |             | 22102018110000 | 2023-12-07    |
      | 2        | Hughes      | Sheldon    | Beverly     | 21081816120000 | 2023-11-13    |
      | 3        | Omar        |            |             | 22060914110000 | 2022-12-01    |
      | 4        |             | Jamie      |             | 22111912100000 | 1970-01-01    |
      | 5        |             |            |             |                |               |

  @Boom.16:9 @Boom.5:4 @Cart
  Scenario Outline: The name and identification number of the patient are visible
    Given the clinical user started the study with identification number "<Study ID>"
    And the current date is "2024-01-01 08:00:00"
    When the clinical user starts the application
    Then the application shows the study is in progress
    And the application shows the name of the patient is "<Display name>"
    And the application shows the identification number of the patient is "<Patient ID>"

    Examples:
      | Study ID | Display name            | Patient ID            |
      | 1        | HIGGINS, Kate           | 22102018110000        |
      | 2        | HUGHES, Sheldon Beverly | 21081816120000        |
      | 3        | OMAR                    | 22060914110000        |
      | 4        | Jamie                   | 22111912100000        |
      | 5        | NoName                  | NoName-20240101080000 |

  @Boom.16:9
  Scenario Outline: The date of birth of the patient is visible
    Given the clinical user started the study with identification number "<Study ID>"
    And the current date is "2024-01-01 08:00:00"
    When the clinical user starts the application
    Then the application shows the date of birth of the patient is "<Date of birth>"
    And the application shows the age of the patient is "<Age>"

    Examples:
      | Study ID | Date of birth | Age |
      | 1        | 2023-12-07    | 25D |
      | 2        | 2023-11-13    | 7W  |
      | 3        | 2022-12-01    | 13M |
      | 4        | 1970-01-01    | 54Y |
