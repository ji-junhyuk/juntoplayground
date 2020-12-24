package spring.HH.controller.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import java.time.LocalDate;

@Data
@NoArgsConstructor
@AllArgsConstructor(staticName = "of")
public class PersonDto {
    @NotBlank(message = "name is necessary.")
    private String name;

    private String hobby;
    private String address;
    private LocalDate birthday;
    private String job;
    private String phoneNumber;
}