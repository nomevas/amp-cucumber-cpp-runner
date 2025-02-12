Feature: Inspection of recorded tomographic images
  In order to allow the clinical user to perform diagnosis of the lesion, plan
  a treatment, or review the deployment of a stent, they must be able to inspect
  the recorded tomographic images.

  @IVUS.CV.Review.DisplayRecordedTomographicImages
  Rule: Display recorded tomographic images
    The application shall display the recorded tomographic images. Additionally,
    the application shall display the frame number as well as the acquisition date
    and time of saved tomographic images, according to the configured regional
    settings. The first frame number is identified as "1".

    Refer to "IMAGE_SIZE.md" for the display size of the tomographic images.

    Scenario: Showing recorded tomographic images
      Given the clinical user started a recording
      And the field of view is configured at "12" millimeters
      When the clinical user stops the recording
      And the application presents the pullback recording
      Then the application presents the tomographic image with frame number "1"
      And the application presents the frame number of the tomographic image
      And the application presents the acquisition date and time of the tomographic image
      And the field of view is configured at "12" millimeters

  @IVUS.CV.Review.DisplayGraticules
  Rule: Display graticules on recorded tomographic images
    The application shall display graticules spaced as supported by the
    catheter. Refer to "DISPOSABLES.md" for the supported graticule spacing.

    Scenario Outline: Showing graticules on the recorded tomographic images
      Given the catheter supports a graticule spacing of "1" millimeter
      And the clinical user started a recording
      And the field of view is configured at "<Field of view>" millimeters
      When the clinical user stops the recording
      And the application presents the pullback recording
      Then the application presents "<Number of graticules>" graticules evenly spaced across the horizontal and vertical axis on the tomographic image

      Examples:
        | Field of view | Number of graticules |
        | 8             | 8                    |
        | 12            | 12                   |
        | 14            | 14                   |
