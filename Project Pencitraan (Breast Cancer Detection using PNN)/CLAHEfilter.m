function Output=CLAHEfilter(InputImage); %#ok<NOSEL>

        level = 0.1;
        Ithresh = imbinarize(InputImage, level);
        Ithresh8 = uint8 (Ithresh).*InputImage;
        
        PSF = fspecial('average',[3 3]);
        SNR = 0.2;
        J = deconvwnr(Ithresh8, PSF,SNR); 
        PreProcessedImage = adapthisteq(J(:,:,1),'NumTiles',[8 8],'ClipLimit',0.01);
        PreProcessedImage = double(PreProcessedImage);
        
        %PreProcessedImage3 = [];
        %PreProcessedImage3(:,:,1) = PreProcessedImage;
        %PreProcessedImage3(:,:,2) = PreProcessedImage;
        %PreProcessedImage3(:,:,3) = PreProcessedImage;

        %PreProcessedImage = PreProcessedImage3;
        %PreProcessedImage = uint8(PreProcessedImage);
                
Output=PreProcessedImage;