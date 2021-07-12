classdef Project1320_exported < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                   matlab.ui.Figure
        TabGroup                   matlab.ui.container.TabGroup
        HomeTab                    matlab.ui.container.Tab
        Image4                     matlab.ui.control.Image
        DasarTeoriTab              matlab.ui.container.Tab
        Image5                     matlab.ui.control.Image
        SoalProjectTab             matlab.ui.container.Tab
        Image6                     matlab.ui.control.Image
        SimulasiTab                matlab.ui.container.Tab
        SinyalInputaxes            matlab.ui.control.UIAxes
        ParameterSinyalInputPanel  matlab.ui.container.Panel
        TimestepmsLabel            matlab.ui.control.Label
        Timestep                   matlab.ui.control.NumericEditField
        SampleEditFieldLabel       matlab.ui.control.Label
        Sample                     matlab.ui.control.NumericEditField
        SinyalEditFieldLabel       matlab.ui.control.Label
        Sinyal                     matlab.ui.control.EditField
        PlotITimeInput             matlab.ui.control.Button
        Outputaxes                 matlab.ui.control.UIAxes
        ResetAllButton             matlab.ui.control.Button
        TabGroup2                  matlab.ui.container.TabGroup
        LowHighTab                 matlab.ui.container.Tab
        JenisFilterButtonGroup_3   matlab.ui.container.ButtonGroup
        LowPass                    matlab.ui.control.RadioButton
        HighPass                   matlab.ui.control.RadioButton
        ParameterFilterButterworthLowHigh  matlab.ui.container.Panel
        FcHzLabel                  matlab.ui.control.Label
        FpLowHigh                  matlab.ui.control.NumericEditField
        OrderLabel                 matlab.ui.control.Label
        FsLowHigh                  matlab.ui.control.NumericEditField
        PlotLowHigh                matlab.ui.control.Button
        BandPassBandStopTab        matlab.ui.container.Tab
        ParameterFilterButterworthPanel  matlab.ui.container.Panel
        FpHzLabel_3                matlab.ui.control.Label
        FpBand                     matlab.ui.control.NumericEditField
        FsHzLabel_3                matlab.ui.control.Label
        FsBand                     matlab.ui.control.NumericEditField
        OrderLabel_2               matlab.ui.control.Label
        OrderBand                  matlab.ui.control.NumericEditField
        JenisFilterButtonGroup_4   matlab.ui.container.ButtonGroup
        BandPass                   matlab.ui.control.RadioButton
        BandStop                   matlab.ui.control.RadioButton
        PlotTimeBand               matlab.ui.control.Button
        fftInputAxes               matlab.ui.control.UIAxes
        fftOutputAxes              matlab.ui.control.UIAxes
        SimulasiAudioTab           matlab.ui.container.Tab
        SinyalInputaxesAudio       matlab.ui.control.UIAxes
        SinyalInputPanel           matlab.ui.container.Panel
        BrowseAudioButton          matlab.ui.control.Button
        PlayButton                 matlab.ui.control.Button
        PlotITimeInputAudio        matlab.ui.control.Button
        StopButton                 matlab.ui.control.Button
        AudioFileText              matlab.ui.control.EditField
        FsEditFieldLabel           matlab.ui.control.Label
        FsAudio                    matlab.ui.control.NumericEditField
        OutputaxesAudio            matlab.ui.control.UIAxes
        ResetAllAudio              matlab.ui.control.Button
        TabGroup2_2                matlab.ui.container.TabGroup
        LowHighTab_2               matlab.ui.container.Tab
        JenisFilterButtonGroup_5   matlab.ui.container.ButtonGroup
        LowPass_2                  matlab.ui.control.RadioButton
        HighPass_2                 matlab.ui.control.RadioButton
        ParameterFilterButterworthLowHigh_2  matlab.ui.container.Panel
        FpkHzLabel                 matlab.ui.control.Label
        FpLowHigh_2                matlab.ui.control.NumericEditField
        OrderNLabel_5              matlab.ui.control.Label
        OrderLowHigh_2             matlab.ui.control.NumericEditField
        PlotLowHighAudio           matlab.ui.control.Button
        PlayFilteredAudioLH        matlab.ui.control.Button
        StopAudioLH                matlab.ui.control.Button
        BandPassBandStopTab_2      matlab.ui.container.Tab
        ParameterFilterButterworthPanel_2  matlab.ui.container.Panel
        FpkHzLabel_2               matlab.ui.control.Label
        FpBand_2                   matlab.ui.control.NumericEditField
        FskHzLabel                 matlab.ui.control.Label
        FsBand_2                   matlab.ui.control.NumericEditField
        OrderLabel_3               matlab.ui.control.Label
        OrderBand_2                matlab.ui.control.NumericEditField
        JenisFilterButtonGroup_6   matlab.ui.container.ButtonGroup
        BandPass_2                 matlab.ui.control.RadioButton
        BandStop_2                 matlab.ui.control.RadioButton
        PlotBandAudio              matlab.ui.control.Button
        PlayFilteredAudioBand      matlab.ui.control.Button
        StopAudioLH_2              matlab.ui.control.Button
        fftInputAxesAudio          matlab.ui.control.UIAxes
        fftOutputAxesAudio         matlab.ui.control.UIAxes
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: PlotITimeInput
        function PlotITimeInputPushed(app, event)
            clc
            close all
            
            T = app.Sample.Value;
            Tss = app.Timestep.Value;
            t = 0:Tss:T;
            L = length(t);
            n = 2^nextpow2(L);
            Fs = 1/Tss;
            
            x = eval(app.Sinyal.Value);
            plot(app.SinyalInputaxes, t, x);
            
            %untuk FFT
            Y = fft(x, n);
            P2 = abs(Y/L);
            f = Fs*(0:(n/2))/n;
            plot(app.fftInputAxes, f, P2(1:n/2+1));
        end

        % Button pushed function: PlotLowHigh
        function PlotLowHighPushed(app, event)
            T = app.Sample.Value;
            Tss = app.Timestep.Value;
            t = 0:Tss:T;
            L = length(t);
            n = 2^nextpow2(L);
            Fs = 1/Tss;
            x = eval(app.Sinyal.Value);
            plot(app.SinyalInputaxes, t, x);
            
            %utk high/low pass filter
            fp = app.FpLowHigh.Value;
            N = app.FsLowHigh.Value; 
            
            if (app.LowPass.Value)
                jenis = 'low';
            end
            
            if (app.HighPass.Value)
                jenis = 'high';
            end

            wn = (fp)*2/Fs;
            [b, a] = butter(N, wn, jenis);
            
            freqs(b,a)
            title(sprintf('Magnitude and Phase Response'))
            
            %Filtering
            u = filter(b,a,x);
            
            %Plot the signal output
            plot(app.Outputaxes, [1:L]/Fs, u);
            
            %FFT
            Y0 = fft(u, n);
            P20 = abs(Y0/L);
            f0 = Fs*(0:(n/2))/n;
            plot(app.fftOutputAxes, f0, P20(1:n/2+1));
        end

        % Button pushed function: PlotTimeBand
        function PlotTimeBandButtonPushed(app, event)
            T = app.Sample.Value;
            Tss = app.Timestep.Value;
            t = 0:Tss:T;
            L = length(t);
            n = 2^nextpow2(L);
            Fs = 1/Tss;
            x = eval(app.Sinyal.Value);
            plot(app.SinyalInputaxes, t, x);
            
            %utk band pass/stop filter
            fp1 = (app.FpBand.Value)*2/Fs;
            fp2 = (app.FsBand.Value)*2/Fs;
            wn = [fp1 fp2];
            N = app.OrderBand.Value;

            if (app.BandPass.Value)
                jenis = 'bandpass';
            end
            
            if (app.BandStop.Value)
                jenis = 'stop';
            end
            
            %Calculate the filter coefficient
            [b, a]=butter(N, wn, jenis);
            
            freqs(b,a)
            title(sprintf('Magnitude and Phase Response'))
            
            %Filtering
            u = filter(b,a,x);
            
            %Plot the signal output
            plot(app.Outputaxes, [1:L]/Fs, u);
            
            %FFT
            Y0 = fft(u, n);
            P20 = abs(Y0/L);
            f0 = Fs*(0:(n/2))/n;
            plot(app.fftOutputAxes, f0, P20(1:n/2+1));
        end

        % Button pushed function: ResetAllButton
        function ResetAllButtonPushed(app, event)
            clc
            close all
            
            app.Timestep.Value = 0;
            app.Sample.Value = 0;
            app.Sinyal.Value = ' ';
            
            app.FpBand.Value = 0;
            app.FsBand.Value = 0;
            app.OrderBand.Value = 0;
            
            app.FpLowHigh.Value = 0;
            app.FsLowHigh.Value = 0; 
            
            cla(app.SinyalInputaxes)
            cla(app.Outputaxes)
            cla(app.fftInputAxes)
            cla(app.fftOutputAxes)
        end

        % Button pushed function: BrowseAudioButton
        function BrowseAudioButtonPushed(app, event)
            global Fs;
            global Audio;
            global player;
            
            [filename, pathname] = uigetfile( ...
                {   '*.wav','WAV File (*.wav)';}, ...
                'Select an Wav File');
            if isequal(filename,0)||isequal(pathname,0)
                app.AudioFileText.Value = 'file not found';
            else
                app.AudioFileText.Value = sprintf(['Selected File : ', filename]);

                [Audio, Fs] = audioread([pathname,filename]);
                player = audioplayer(Audio, Fs);
                
                app.FsAudio.Value = Fs;
            end
        end

        % Button pushed function: PlayButton
        function PlayButtonPushed(app, event)
            global player;
            play(player);
        end

        % Button pushed function: StopButton
        function StopButtonPushed(app, event)
            global player;
            stop(player);
        end

        % Button pushed function: PlotITimeInputAudio
        function PlotITimeInputAudioButtonPushed(app, event)
            global Audio;
            global Fs;
            
            t = 0:1/Fs:(length(Audio)-1)/Fs;
            L = length(t);
            n = pow2(nextpow2(L));
            
            Y = fft(Audio, n);
            P2 = abs(Y).^2/n;
            f = (0:n-1)*(Fs/n)/10;
            
            plot(app.fftInputAxesAudio, f(1:floor(n/2)),P2(1:floor(n/2)))
            
            plot(app.SinyalInputaxesAudio, t, Audio);
        end

        % Button pushed function: PlotLowHighAudio
        function PlotLowHighAudioButtonPushed(app, event)
            global Audio;
            global Audiofilt;
            global Fs;
            global player2;
            
            t = 0:1/Fs:(length(Audio)-1)/Fs;
            L = length(t);
            n = pow2(nextpow2(L));
            
            %utk high/low pass filter
            fp = app.FpLowHigh_2.Value;
            N = app.OrderLowHigh_2.Value; 
            
            if (app.LowPass_2.Value)
                jenis = 'low';
            end
            
            if (app.HighPass_2.Value)
                jenis = 'high';
            end
            
            %Normalized the frequencies
            wn=(fp)*2/Fs;
           
            %Calculate the filter coefficient
            [b, a] = butter(N,wn, jenis);

            freqs(b,a);
            title(sprintf('Magnitude and Phase Response'))
            
            %Filtering
            Audiofilt = filter(b,a,Audio);
            player2 = audioplayer(Audiofilt,Fs);
            
            %Plot the signal output
            plot(app.OutputaxesAudio, Audiofilt);
            
            %FFT
            Y0 = fft(Audiofilt, n);
            P20 = abs(Y0).^2/n;
            f0 = (0:n-1)*(Fs/n)/10;
            plot(app.fftOutputAxesAudio, f0(1:floor(n/2)),P20(1:floor(n/2)));
        end

        % Button pushed function: PlayFilteredAudioLH
        function PlayFilteredAudioLHButtonPushed(app, event)
           global player2;
           play(player2); 
        end

        % Button pushed function: PlotBandAudio
        function PlotBandAudioButtonPushed(app, event)
            global Audio;
            global AudiofiltB;
            global Fs;
            global player2B;
            
            t = 0:1/Fs:(length(Audio)-1)/Fs;
            L = length(t);
            n = pow2(nextpow2(L));
            
            %utk band pass/stop filter
            fp1 = (app.FpBand_2.Value)*2/Fs;
            fp2 = (app.FsBand_2.Value)*2/Fs;
            wn = [fp1 fp2];
            
            N = app.OrderBand_2.Value;
            
            if (app.BandPass_2.Value)
                jenis = 'bandpass';
            end
            
            if (app.BandStop_2.Value)
                jenis = 'stop';
            end

            %Calculate the filter coefficient
            [b, a]=butter(N, wn, jenis);
            
            freqs(b,a)
            title(sprintf('Magnitude and Phase Response'))
            
            %Filtering
            AudiofiltB = filter(b,a,Audio);
            player2B = audioplayer(AudiofiltB,Fs);
            
            %Plot the signal output
            plot(app.Outputaxes, AudiofiltB);
            
            %FFT
            Y0 = fft(AudiofiltB, n);
            P20 = abs(Y0).^2/n;
            f0 = (0:n-1)*(Fs/n)/10;
            plot(app.fftOutputAxesAudio, f0(1:floor(n/2)),P20(1:floor(n/2)));
        end

        % Button pushed function: PlayFilteredAudioBand
        function PlayFilteredAudioBandButtonPushed(app, event)
           global player2B;
           play(player2B); 
        end

        % Button pushed function: ResetAllAudio
        function ResetAllAudioButtonPushed(app, event)
            clc
            close all

            app.FpBand_2.Value = 0;
            app.FsBand_2.Value = 0;
            app.OrderBand_2.Value = 0;
            app.FsAudio.Value = 0;
            
            app.FpLowHigh_2.Value = 0;
            app.OrderLowHigh_2.Value = 0;
            
            cla(app.SinyalInputaxesAudio)
            cla(app.OutputaxesAudio)
            cla(app.fftInputAxesAudio)
            cla(app.fftOutputAxesAudio)
        end

        % Button pushed function: StopAudioLH
        function StopAudioLHButtonPushed(app, event)
           global player2;
           stop(player2);
        end

        % Button pushed function: StopAudioLH_2
        function StopAudioLH_2ButtonPushed(app, event)
           global player2B;
           stop(player2B);
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.Position = [100 100 700 1000];
            app.UIFigure.Name = 'UI Figure';
            app.UIFigure.Scrollable = 'on';

            % Create TabGroup
            app.TabGroup = uitabgroup(app.UIFigure);
            app.TabGroup.Position = [38 22 641 934];

            % Create HomeTab
            app.HomeTab = uitab(app.TabGroup);
            app.HomeTab.Title = 'Home';
            app.HomeTab.BackgroundColor = [1 0.9412 0.7961];
            app.HomeTab.Scrollable = 'on';

            % Create Image4
            app.Image4 = uiimage(app.HomeTab);
            app.Image4.Position = [18 34 590 856];
            app.Image4.ImageSource = 'Home.jpg';

            % Create DasarTeoriTab
            app.DasarTeoriTab = uitab(app.TabGroup);
            app.DasarTeoriTab.Title = 'Dasar Teori';
            app.DasarTeoriTab.BackgroundColor = [0 0.2902 0.6784];
            app.DasarTeoriTab.Scrollable = 'on';

            % Create Image5
            app.Image5 = uiimage(app.DasarTeoriTab);
            app.Image5.Position = [21 36 578 834];
            app.Image5.ImageSource = '2.jpg';

            % Create SoalProjectTab
            app.SoalProjectTab = uitab(app.TabGroup);
            app.SoalProjectTab.Title = 'Soal Project';
            app.SoalProjectTab.BackgroundColor = [1 1 1];
            app.SoalProjectTab.Scrollable = 'on';

            % Create Image6
            app.Image6 = uiimage(app.SoalProjectTab);
            app.Image6.Position = [35 44 555 805];
            app.Image6.ImageSource = 'soal2.jpg';

            % Create SimulasiTab
            app.SimulasiTab = uitab(app.TabGroup);
            app.SimulasiTab.Title = 'Simulasi';
            app.SimulasiTab.BackgroundColor = [1 0.8706 0.349];
            app.SimulasiTab.Scrollable = 'on';

            % Create SinyalInputaxes
            app.SinyalInputaxes = uiaxes(app.SimulasiTab);
            title(app.SinyalInputaxes, 'Sinyal Input Domain Waktu')
            xlabel(app.SinyalInputaxes, 'Time (ms)')
            ylabel(app.SinyalInputaxes, 'Amplitude')
            app.SinyalInputaxes.Position = [293 699 320 196];

            % Create ParameterSinyalInputPanel
            app.ParameterSinyalInputPanel = uipanel(app.SimulasiTab);
            app.ParameterSinyalInputPanel.BorderType = 'none';
            app.ParameterSinyalInputPanel.Title = 'Parameter Sinyal Input';
            app.ParameterSinyalInputPanel.BackgroundColor = [1 0.8706 0.349];
            app.ParameterSinyalInputPanel.FontWeight = 'bold';
            app.ParameterSinyalInputPanel.Position = [10 678 274 148];

            % Create TimestepmsLabel
            app.TimestepmsLabel = uilabel(app.ParameterSinyalInputPanel);
            app.TimestepmsLabel.HorizontalAlignment = 'right';
            app.TimestepmsLabel.Position = [123 94 85 22];
            app.TimestepmsLabel.Text = 'Time step (ms)';

            % Create Timestep
            app.Timestep = uieditfield(app.ParameterSinyalInputPanel, 'numeric');
            app.Timestep.Tooltip = {'Time Step Value'; '(in ms)'; 'ex = 0.025'};
            app.Timestep.Position = [223 94 46 22];

            % Create SampleEditFieldLabel
            app.SampleEditFieldLabel = uilabel(app.ParameterSinyalInputPanel);
            app.SampleEditFieldLabel.HorizontalAlignment = 'right';
            app.SampleEditFieldLabel.Position = [10 94 46 22];
            app.SampleEditFieldLabel.Text = 'Sample';

            % Create Sample
            app.Sample = uieditfield(app.ParameterSinyalInputPanel, 'numeric');
            app.Sample.Tooltip = {'Sample of the input'; 'ex : 200'};
            app.Sample.Position = [71 94 45 22];

            % Create SinyalEditFieldLabel
            app.SinyalEditFieldLabel = uilabel(app.ParameterSinyalInputPanel);
            app.SinyalEditFieldLabel.HorizontalAlignment = 'right';
            app.SinyalEditFieldLabel.Position = [66 47 38 22];
            app.SinyalEditFieldLabel.Text = 'Sinyal';

            % Create Sinyal
            app.Sinyal = uieditfield(app.ParameterSinyalInputPanel, 'text');
            app.Sinyal.Tooltip = {'Input signal equation'; 'Format : amp1*sin((2*pi*f1*t) + phase1) - amp2*sin((2*pi*f2*t) + phase2) + ...'; 'amp1&2 = amplitude'; 'f1&f2 = frequency'; 'phase1&2 =  phase'; 'ex: sin(2*pi*5000*t) + 10*sin(2*pi*15000*t)'};
            app.Sinyal.Position = [119 47 100 22];

            % Create PlotITimeInput
            app.PlotITimeInput = uibutton(app.ParameterSinyalInputPanel, 'push');
            app.PlotITimeInput.ButtonPushedFcn = createCallbackFcn(app, @PlotITimeInputPushed, true);
            app.PlotITimeInput.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotITimeInput.Position = [93 10 100 22];
            app.PlotITimeInput.Text = 'Plot';

            % Create Outputaxes
            app.Outputaxes = uiaxes(app.SimulasiTab);
            title(app.Outputaxes, 'Sinyal Output Domain Waktu')
            xlabel(app.Outputaxes, 'Time (ms)')
            ylabel(app.Outputaxes, 'Amplitude')
            app.Outputaxes.Position = [293 268 320 196];

            % Create ResetAllButton
            app.ResetAllButton = uibutton(app.SimulasiTab, 'push');
            app.ResetAllButton.ButtonPushedFcn = createCallbackFcn(app, @ResetAllButtonPushed, true);
            app.ResetAllButton.BackgroundColor = [1 0.4118 0.1608];
            app.ResetAllButton.Position = [513 16 100 22];
            app.ResetAllButton.Text = 'Reset All';

            % Create TabGroup2
            app.TabGroup2 = uitabgroup(app.SimulasiTab);
            app.TabGroup2.Position = [13 183 268 281];

            % Create LowHighTab
            app.LowHighTab = uitab(app.TabGroup2);
            app.LowHighTab.Title = 'Low / High';
            app.LowHighTab.BackgroundColor = [1 0.8706 0.349];

            % Create JenisFilterButtonGroup_3
            app.JenisFilterButtonGroup_3 = uibuttongroup(app.LowHighTab);
            app.JenisFilterButtonGroup_3.BorderType = 'none';
            app.JenisFilterButtonGroup_3.Title = 'Jenis Filter';
            app.JenisFilterButtonGroup_3.BackgroundColor = [1 0.8706 0.349];
            app.JenisFilterButtonGroup_3.FontWeight = 'bold';
            app.JenisFilterButtonGroup_3.Position = [13 23 125 78];

            % Create LowPass
            app.LowPass = uiradiobutton(app.JenisFilterButtonGroup_3);
            app.LowPass.Text = 'Low Pass';
            app.LowPass.Position = [8 33 74 22];
            app.LowPass.Value = true;

            % Create HighPass
            app.HighPass = uiradiobutton(app.JenisFilterButtonGroup_3);
            app.HighPass.Text = 'High Pass';
            app.HighPass.Position = [8 2 77 22];

            % Create ParameterFilterButterworthLowHigh
            app.ParameterFilterButterworthLowHigh = uipanel(app.LowHighTab);
            app.ParameterFilterButterworthLowHigh.BorderType = 'none';
            app.ParameterFilterButterworthLowHigh.Title = 'Parameter Filter Butterworth';
            app.ParameterFilterButterworthLowHigh.BackgroundColor = [1 0.8706 0.349];
            app.ParameterFilterButterworthLowHigh.FontWeight = 'bold';
            app.ParameterFilterButterworthLowHigh.Position = [10 113 247 131];

            % Create FcHzLabel
            app.FcHzLabel = uilabel(app.ParameterFilterButterworthLowHigh);
            app.FcHzLabel.HorizontalAlignment = 'right';
            app.FcHzLabel.Position = [14 59 45 22];
            app.FcHzLabel.Text = 'Fc (Hz)';

            % Create FpLowHigh
            app.FpLowHigh = uieditfield(app.ParameterFilterButterworthLowHigh, 'numeric');
            app.FpLowHigh.Tooltip = {'Input cut-off Frequency (Hz)'; 'ex : 10000, 1000'};
            app.FpLowHigh.Position = [74 59 45 22];

            % Create OrderLabel
            app.OrderLabel = uilabel(app.ParameterFilterButterworthLowHigh);
            app.OrderLabel.HorizontalAlignment = 'right';
            app.OrderLabel.Position = [142 59 36 22];
            app.OrderLabel.Text = 'Order';

            % Create FsLowHigh
            app.FsLowHigh = uieditfield(app.ParameterFilterButterworthLowHigh, 'numeric');
            app.FsLowHigh.Tooltip = {'Input the Order of the Filter'; 'ex : 5'};
            app.FsLowHigh.Position = [193 59 45 22];

            % Create PlotLowHigh
            app.PlotLowHigh = uibutton(app.LowHighTab, 'push');
            app.PlotLowHigh.ButtonPushedFcn = createCallbackFcn(app, @PlotLowHighPushed, true);
            app.PlotLowHigh.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotLowHigh.Position = [149 51 100 22];
            app.PlotLowHigh.Text = 'Filter and Plot';

            % Create BandPassBandStopTab
            app.BandPassBandStopTab = uitab(app.TabGroup2);
            app.BandPassBandStopTab.Title = 'Band Pass / Band Stop';
            app.BandPassBandStopTab.BackgroundColor = [1 0.8706 0.349];

            % Create ParameterFilterButterworthPanel
            app.ParameterFilterButterworthPanel = uipanel(app.BandPassBandStopTab);
            app.ParameterFilterButterworthPanel.BorderType = 'none';
            app.ParameterFilterButterworthPanel.Title = 'Parameter Filter Butterworth';
            app.ParameterFilterButterworthPanel.BackgroundColor = [1 0.8706 0.349];
            app.ParameterFilterButterworthPanel.FontWeight = 'bold';
            app.ParameterFilterButterworthPanel.Position = [12 118 247 130];

            % Create FpHzLabel_3
            app.FpHzLabel_3 = uilabel(app.ParameterFilterButterworthPanel);
            app.FpHzLabel_3.HorizontalAlignment = 'right';
            app.FpHzLabel_3.Position = [15 79 45 22];
            app.FpHzLabel_3.Text = 'Fp (Hz)';

            % Create FpBand
            app.FpBand = uieditfield(app.ParameterFilterButterworthPanel, 'numeric');
            app.FpBand.Tooltip = {'Input the lower frequency'; 'ex : 100'};
            app.FpBand.Position = [75 79 45 22];

            % Create FsHzLabel_3
            app.FsHzLabel_3 = uilabel(app.ParameterFilterButterworthPanel);
            app.FsHzLabel_3.HorizontalAlignment = 'right';
            app.FsHzLabel_3.Position = [138 79 45 22];
            app.FsHzLabel_3.Text = 'Fs (Hz)';

            % Create FsBand
            app.FsBand = uieditfield(app.ParameterFilterButterworthPanel, 'numeric');
            app.FsBand.Tooltip = {'Input the higher frequency'; 'ex : 3000'};
            app.FsBand.Position = [198 79 45 22];

            % Create OrderLabel_2
            app.OrderLabel_2 = uilabel(app.ParameterFilterButterworthPanel);
            app.OrderLabel_2.HorizontalAlignment = 'right';
            app.OrderLabel_2.Position = [146 38 36 22];
            app.OrderLabel_2.Text = 'Order';

            % Create OrderBand
            app.OrderBand = uieditfield(app.ParameterFilterButterworthPanel, 'numeric');
            app.OrderBand.Tooltip = {'Input frequency stop band 2 (Hz).'; 'Note : fs1 < fp1 < fp2 < fs2'; 'ex : 4000'};
            app.OrderBand.Position = [197 38 45 22];

            % Create JenisFilterButtonGroup_4
            app.JenisFilterButtonGroup_4 = uibuttongroup(app.BandPassBandStopTab);
            app.JenisFilterButtonGroup_4.BorderType = 'none';
            app.JenisFilterButtonGroup_4.Title = 'Jenis Filter';
            app.JenisFilterButtonGroup_4.BackgroundColor = [1 0.8706 0.349];
            app.JenisFilterButtonGroup_4.FontWeight = 'bold';
            app.JenisFilterButtonGroup_4.Position = [16 10 125 86];

            % Create BandPass
            app.BandPass = uiradiobutton(app.JenisFilterButtonGroup_4);
            app.BandPass.Text = 'Band Pass';
            app.BandPass.Position = [8 41 80 22];
            app.BandPass.Value = true;

            % Create BandStop
            app.BandStop = uiradiobutton(app.JenisFilterButtonGroup_4);
            app.BandStop.Text = 'Band Stop';
            app.BandStop.Position = [8 10 78 22];

            % Create PlotTimeBand
            app.PlotTimeBand = uibutton(app.BandPassBandStopTab, 'push');
            app.PlotTimeBand.ButtonPushedFcn = createCallbackFcn(app, @PlotTimeBandButtonPushed, true);
            app.PlotTimeBand.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotTimeBand.Position = [155 47 100 22];
            app.PlotTimeBand.Text = 'Filter and Plot';

            % Create fftInputAxes
            app.fftInputAxes = uiaxes(app.SimulasiTab);
            title(app.fftInputAxes, 'Sinyal Input Domain Frequency')
            xlabel(app.fftInputAxes, 'Frequency (Hz)')
            ylabel(app.fftInputAxes, 'Amplitude')
            app.fftInputAxes.Position = [293 477 320 202];

            % Create fftOutputAxes
            app.fftOutputAxes = uiaxes(app.SimulasiTab);
            title(app.fftOutputAxes, 'Sinyal Output Domain Frequency')
            xlabel(app.fftOutputAxes, 'Frequency (Hz)')
            ylabel(app.fftOutputAxes, '|P1(f)|')
            app.fftOutputAxes.Position = [293 52 320 200];

            % Create SimulasiAudioTab
            app.SimulasiAudioTab = uitab(app.TabGroup);
            app.SimulasiAudioTab.Title = 'Simulasi';
            app.SimulasiAudioTab.BackgroundColor = [1 0.8706 0.349];
            app.SimulasiAudioTab.Scrollable = 'on';

            % Create SinyalInputaxesAudio
            app.SinyalInputaxesAudio = uiaxes(app.SimulasiAudioTab);
            title(app.SinyalInputaxesAudio, 'Sinyal Input Domain Waktu')
            xlabel(app.SinyalInputaxesAudio, 'Time (ms)')
            ylabel(app.SinyalInputaxesAudio, 'Amplitude')
            app.SinyalInputaxesAudio.Position = [293 699 320 196];

            % Create SinyalInputPanel
            app.SinyalInputPanel = uipanel(app.SimulasiAudioTab);
            app.SinyalInputPanel.BorderType = 'none';
            app.SinyalInputPanel.Title = 'Sinyal Input';
            app.SinyalInputPanel.BackgroundColor = [1 0.8706 0.349];
            app.SinyalInputPanel.FontWeight = 'bold';
            app.SinyalInputPanel.Position = [10 613 274 213];

            % Create BrowseAudioButton
            app.BrowseAudioButton = uibutton(app.SinyalInputPanel, 'push');
            app.BrowseAudioButton.ButtonPushedFcn = createCallbackFcn(app, @BrowseAudioButtonPushed, true);
            app.BrowseAudioButton.Tooltip = {'Browse audio file from your directory (.wav)'};
            app.BrowseAudioButton.Position = [14 152 100 22];
            app.BrowseAudioButton.Text = 'Browse Audio';

            % Create PlayButton
            app.PlayButton = uibutton(app.SinyalInputPanel, 'push');
            app.PlayButton.ButtonPushedFcn = createCallbackFcn(app, @PlayButtonPushed, true);
            app.PlayButton.Position = [11 55 100 22];
            app.PlayButton.Text = 'Play';

            % Create PlotITimeInputAudio
            app.PlotITimeInputAudio = uibutton(app.SinyalInputPanel, 'push');
            app.PlotITimeInputAudio.ButtonPushedFcn = createCallbackFcn(app, @PlotITimeInputAudioButtonPushed, true);
            app.PlotITimeInputAudio.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotITimeInputAudio.Position = [91 19 100 22];
            app.PlotITimeInputAudio.Text = 'Plot';

            % Create StopButton
            app.StopButton = uibutton(app.SinyalInputPanel, 'push');
            app.StopButton.ButtonPushedFcn = createCallbackFcn(app, @StopButtonPushed, true);
            app.StopButton.Position = [158 55 100 22];
            app.StopButton.Text = 'Stop';

            % Create AudioFileText
            app.AudioFileText = uieditfield(app.SinyalInputPanel, 'text');
            app.AudioFileText.Position = [120 152 144 22];

            % Create FsEditFieldLabel
            app.FsEditFieldLabel = uilabel(app.SinyalInputPanel);
            app.FsEditFieldLabel.HorizontalAlignment = 'right';
            app.FsEditFieldLabel.Position = [75 106 25 22];
            app.FsEditFieldLabel.Text = 'Fs';

            % Create FsAudio
            app.FsAudio = uieditfield(app.SinyalInputPanel, 'numeric');
            app.FsAudio.Tooltip = {'Frequency sample of the audio file (Hz)'};
            app.FsAudio.Position = [115 106 100 22];

            % Create OutputaxesAudio
            app.OutputaxesAudio = uiaxes(app.SimulasiAudioTab);
            title(app.OutputaxesAudio, 'Sinyal Output Domain Waktu')
            xlabel(app.OutputaxesAudio, 'Time (ms)')
            ylabel(app.OutputaxesAudio, 'Amplitude')
            app.OutputaxesAudio.Position = [293 268 320 196];

            % Create ResetAllAudio
            app.ResetAllAudio = uibutton(app.SimulasiAudioTab, 'push');
            app.ResetAllAudio.ButtonPushedFcn = createCallbackFcn(app, @ResetAllAudioButtonPushed, true);
            app.ResetAllAudio.BackgroundColor = [1 0.4118 0.1608];
            app.ResetAllAudio.Position = [513 33 100 22];
            app.ResetAllAudio.Text = 'Reset All';

            % Create TabGroup2_2
            app.TabGroup2_2 = uitabgroup(app.SimulasiAudioTab);
            app.TabGroup2_2.Position = [13 150 268 314];

            % Create LowHighTab_2
            app.LowHighTab_2 = uitab(app.TabGroup2_2);
            app.LowHighTab_2.Title = 'Low / High';
            app.LowHighTab_2.BackgroundColor = [1 0.8706 0.349];

            % Create JenisFilterButtonGroup_5
            app.JenisFilterButtonGroup_5 = uibuttongroup(app.LowHighTab_2);
            app.JenisFilterButtonGroup_5.BorderType = 'none';
            app.JenisFilterButtonGroup_5.Title = 'Jenis Filter';
            app.JenisFilterButtonGroup_5.BackgroundColor = [1 0.8706 0.349];
            app.JenisFilterButtonGroup_5.FontWeight = 'bold';
            app.JenisFilterButtonGroup_5.Position = [13 56 125 78];

            % Create LowPass_2
            app.LowPass_2 = uiradiobutton(app.JenisFilterButtonGroup_5);
            app.LowPass_2.Text = 'Low Pass';
            app.LowPass_2.Position = [8 33 74 22];
            app.LowPass_2.Value = true;

            % Create HighPass_2
            app.HighPass_2 = uiradiobutton(app.JenisFilterButtonGroup_5);
            app.HighPass_2.Text = 'High Pass';
            app.HighPass_2.Position = [8 2 77 22];

            % Create ParameterFilterButterworthLowHigh_2
            app.ParameterFilterButterworthLowHigh_2 = uipanel(app.LowHighTab_2);
            app.ParameterFilterButterworthLowHigh_2.BorderType = 'none';
            app.ParameterFilterButterworthLowHigh_2.Title = 'Parameter Filter Butterworth';
            app.ParameterFilterButterworthLowHigh_2.BackgroundColor = [1 0.8706 0.349];
            app.ParameterFilterButterworthLowHigh_2.FontWeight = 'bold';
            app.ParameterFilterButterworthLowHigh_2.Position = [10 146 247 131];

            % Create FpkHzLabel
            app.FpkHzLabel = uilabel(app.ParameterFilterButterworthLowHigh_2);
            app.FpkHzLabel.HorizontalAlignment = 'right';
            app.FpkHzLabel.Position = [8 59 51 22];
            app.FpkHzLabel.Text = 'Fp (kHz)';

            % Create FpLowHigh_2
            app.FpLowHigh_2 = uieditfield(app.ParameterFilterButterworthLowHigh_2, 'numeric');
            app.FpLowHigh_2.Tooltip = {'Input cutoff Frequency (Hz)'; 'ex : 10000, 1000'};
            app.FpLowHigh_2.Position = [74 59 45 22];

            % Create OrderNLabel_5
            app.OrderNLabel_5 = uilabel(app.ParameterFilterButterworthLowHigh_2);
            app.OrderNLabel_5.HorizontalAlignment = 'right';
            app.OrderNLabel_5.Position = [132 59 61 22];
            app.OrderNLabel_5.Text = 'Order (N)';

            % Create OrderLowHigh_2
            app.OrderLowHigh_2 = uieditfield(app.ParameterFilterButterworthLowHigh_2, 'numeric');
            app.OrderLowHigh_2.Tooltip = {'Input the order of the filter'; 'ex : 5'};
            app.OrderLowHigh_2.Position = [203 59 35 22];

            % Create PlotLowHighAudio
            app.PlotLowHighAudio = uibutton(app.LowHighTab_2, 'push');
            app.PlotLowHighAudio.ButtonPushedFcn = createCallbackFcn(app, @PlotLowHighAudioButtonPushed, true);
            app.PlotLowHighAudio.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotLowHighAudio.Position = [149 109 100 22];
            app.PlotLowHighAudio.Text = 'Filter and Plot';

            % Create PlayFilteredAudioLH
            app.PlayFilteredAudioLH = uibutton(app.LowHighTab_2, 'push');
            app.PlayFilteredAudioLH.ButtonPushedFcn = createCallbackFcn(app, @PlayFilteredAudioLHButtonPushed, true);
            app.PlayFilteredAudioLH.Position = [141 78 116 22];
            app.PlayFilteredAudioLH.Text = 'Play Filtered Audio';

            % Create StopAudioLH
            app.StopAudioLH = uibutton(app.LowHighTab_2, 'push');
            app.StopAudioLH.ButtonPushedFcn = createCallbackFcn(app, @StopAudioLHButtonPushed, true);
            app.StopAudioLH.Position = [149 44 100 22];
            app.StopAudioLH.Text = 'Stop';

            % Create BandPassBandStopTab_2
            app.BandPassBandStopTab_2 = uitab(app.TabGroup2_2);
            app.BandPassBandStopTab_2.Title = 'Band Pass / Band Stop';
            app.BandPassBandStopTab_2.BackgroundColor = [1 0.8706 0.349];

            % Create ParameterFilterButterworthPanel_2
            app.ParameterFilterButterworthPanel_2 = uipanel(app.BandPassBandStopTab_2);
            app.ParameterFilterButterworthPanel_2.BorderType = 'none';
            app.ParameterFilterButterworthPanel_2.Title = 'Parameter Filter Butterworth';
            app.ParameterFilterButterworthPanel_2.BackgroundColor = [1 0.8706 0.349];
            app.ParameterFilterButterworthPanel_2.FontWeight = 'bold';
            app.ParameterFilterButterworthPanel_2.Position = [12 128 247 153];

            % Create FpkHzLabel_2
            app.FpkHzLabel_2 = uilabel(app.ParameterFilterButterworthPanel_2);
            app.FpkHzLabel_2.HorizontalAlignment = 'right';
            app.FpkHzLabel_2.Position = [9 102 51 22];
            app.FpkHzLabel_2.Text = 'Fp (kHz)';

            % Create FpBand_2
            app.FpBand_2 = uieditfield(app.ParameterFilterButterworthPanel_2, 'numeric');
            app.FpBand_2.Tooltip = {'Input lower frequency (Hz)'; 'ex : 2000'};
            app.FpBand_2.Position = [75 102 45 22];

            % Create FskHzLabel
            app.FskHzLabel = uilabel(app.ParameterFilterButterworthPanel_2);
            app.FskHzLabel.HorizontalAlignment = 'right';
            app.FskHzLabel.Position = [132 102 51 22];
            app.FskHzLabel.Text = 'Fs (kHz)';

            % Create FsBand_2
            app.FsBand_2 = uieditfield(app.ParameterFilterButterworthPanel_2, 'numeric');
            app.FsBand_2.Tooltip = {'Input higher frequency (Hz)'; 'ex : 2000'};
            app.FsBand_2.Position = [198 102 45 22];

            % Create OrderLabel_3
            app.OrderLabel_3 = uilabel(app.ParameterFilterButterworthPanel_2);
            app.OrderLabel_3.HorizontalAlignment = 'right';
            app.OrderLabel_3.Position = [172 66 36 22];
            app.OrderLabel_3.Text = 'Order';

            % Create OrderBand_2
            app.OrderBand_2 = uieditfield(app.ParameterFilterButterworthPanel_2, 'numeric');
            app.OrderBand_2.Tooltip = {'Input  Attenuation Magnitude (dB)'; 'ex : 3'};
            app.OrderBand_2.Position = [211 66 30 22];

            % Create JenisFilterButtonGroup_6
            app.JenisFilterButtonGroup_6 = uibuttongroup(app.BandPassBandStopTab_2);
            app.JenisFilterButtonGroup_6.BorderType = 'none';
            app.JenisFilterButtonGroup_6.Title = 'Jenis Filter';
            app.JenisFilterButtonGroup_6.BackgroundColor = [1 0.8706 0.349];
            app.JenisFilterButtonGroup_6.FontWeight = 'bold';
            app.JenisFilterButtonGroup_6.Position = [16 30 125 86];

            % Create BandPass_2
            app.BandPass_2 = uiradiobutton(app.JenisFilterButtonGroup_6);
            app.BandPass_2.Text = 'Band Pass';
            app.BandPass_2.Position = [8 41 80 22];
            app.BandPass_2.Value = true;

            % Create BandStop_2
            app.BandStop_2 = uiradiobutton(app.JenisFilterButtonGroup_6);
            app.BandStop_2.Text = 'Band Stop';
            app.BandStop_2.Position = [8 10 78 22];

            % Create PlotBandAudio
            app.PlotBandAudio = uibutton(app.BandPassBandStopTab_2, 'push');
            app.PlotBandAudio.ButtonPushedFcn = createCallbackFcn(app, @PlotBandAudioButtonPushed, true);
            app.PlotBandAudio.BackgroundColor = [0.9294 0.6941 0.1255];
            app.PlotBandAudio.Position = [154 97 100 22];
            app.PlotBandAudio.Text = 'Filter and Plot';

            % Create PlayFilteredAudioBand
            app.PlayFilteredAudioBand = uibutton(app.BandPassBandStopTab_2, 'push');
            app.PlayFilteredAudioBand.ButtonPushedFcn = createCallbackFcn(app, @PlayFilteredAudioBandButtonPushed, true);
            app.PlayFilteredAudioBand.Position = [144 62 116 22];
            app.PlayFilteredAudioBand.Text = 'Play Filtered Audio';

            % Create StopAudioLH_2
            app.StopAudioLH_2 = uibutton(app.BandPassBandStopTab_2, 'push');
            app.StopAudioLH_2.ButtonPushedFcn = createCallbackFcn(app, @StopAudioLH_2ButtonPushed, true);
            app.StopAudioLH_2.Position = [152 31 100 22];
            app.StopAudioLH_2.Text = 'Stop';

            % Create fftInputAxesAudio
            app.fftInputAxesAudio = uiaxes(app.SimulasiAudioTab);
            title(app.fftInputAxesAudio, 'Sinyal Input Domain Frequency')
            xlabel(app.fftInputAxesAudio, 'Frequency (Hz)')
            ylabel(app.fftInputAxesAudio, 'Amplitude')
            app.fftInputAxesAudio.Position = [293 477 320 202];

            % Create fftOutputAxesAudio
            app.fftOutputAxesAudio = uiaxes(app.SimulasiAudioTab);
            title(app.fftOutputAxesAudio, 'Sinyal Output Domain Frequency')
            xlabel(app.fftOutputAxesAudio, 'Frequency (Hz)')
            ylabel(app.fftOutputAxesAudio, '|P1(f)|')
            app.fftOutputAxesAudio.Position = [293 64 320 191];

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = Project1320_exported

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end